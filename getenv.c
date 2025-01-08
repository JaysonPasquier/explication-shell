#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
    char *variable, *equal_sign, *value;  // Déclare des pointeurs pour stocker des chaînes
    int compare;  // Déclare une variable pour stocker le résultat de la comparaison
    unsigned int path_length, length, i;  // Déclare des variables pour les longueurs et l'itération
    char *path;  // Déclare un pointeur pour stocker le chemin

    length = _strlen((char *)name);  // Obtient la longueur du nom de la variable d'environnement
    i = 0;  // Initialise i à 0

    while (environ[i] != NULL)  // Boucle à travers toutes les variables d'environnement
    {
        variable = environ[i];  // Obtient la variable d'environnement courante
        compare = _strncmp((char *)name, variable, length);  // Compare le nom avec la variable courante
        if (compare == 1)  // Si les chaînes sont égales
        {
            equal_sign = strchr(variable, '=');  // Trouve le signe égal dans la variable
            if (equal_sign != NULL)  // Si le signe égal est trouvé
            {
                value = equal_sign + 1;  // Obtient la valeur après le signe égal

                if (value == NULL || *value == '\0')  // Si la valeur est NULL ou vide
                {
                    errors(4);  // Affiche une erreur
                    exit(EXIT_FAILURE);  // Quitte le programme
                }

                path_length = _strlen(value);  // Obtient la longueur de la valeur
                path = malloc(sizeof(char) * path_length + 1);  // Alloue de la mémoire pour le chemin
                if (path == NULL)  // Si l'allocation échoue
                {
                    errors(3);  // Affiche une erreur
                    return (NULL);  // Retourne NULL
                }
                path = _strcpy(path, value);  // Copie la valeur dans le chemin
                return (path);  // Retourne le chemin
            }
        }
        i++;  // Passe à la prochaine variable d'environnement
    }

    return (NULL);  // Retourne NULL si la variable n'est pas trouvée
}
