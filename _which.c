#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *fullpath, char *path)
{
    unsigned int command_length, path_length, original_path_length;  // Déclare des variables pour stocker les longueurs
    char *path_copy, *token;  // Déclare des pointeurs pour la copie du chemin et le token

    command_length = _strlen(command);  // Obtient la longueur de la commande
    original_path_length = _strlen(path);  // Obtient la longueur du chemin original
    path_copy = malloc(sizeof(char) * original_path_length + 1);  // Alloue de la mémoire pour la copie du chemin
    if (path_copy == NULL)  // Vérifie si l'allocation a échoué
    {
        errors(3);  // Appelle la fonction errors avec le code 3
        return (NULL);  // Retourne NULL en cas d'échec
    }
    _strcpy(path_copy, path);  // Copie le chemin original dans path_copy
    token = strtok(path_copy, ":");  // Divise path_copy en tokens en utilisant ":" comme délimiteur
    if (token == NULL)  // Si aucun token n'est trouvé
        token = strtok(NULL, ":");  // Essaie de trouver le prochain token
    while (token != NULL)  // Boucle tant qu'il y a des tokens
    {
        path_length = _strlen(token);  // Obtient la longueur du token actuel
        fullpath = malloc(sizeof(char) * (path_length + command_length) + 2);  // Alloue de la mémoire pour le chemin complet
        if (fullpath == NULL)  // Vérifie si l'allocation a échoué
        {
            errors(3);  // Appelle la fonction errors avec le code 3
            return (NULL);  // Retourne NULL en cas d'échec
        }
        _strcpy(fullpath, token);  // Copie le token dans fullpath
        fullpath[path_length] = '/';  // Ajoute un '/' à la fin du chemin
        _strcpy(fullpath + path_length + 1, command);  // Ajoute la commande après le '/'
        fullpath[path_length + command_length + 1] = '\0';  // Ajoute le caractère nul à la fin
        if (access(fullpath, X_OK) != 0)  // Vérifie si le fichier est exécutable
        {
            free(fullpath);  // Libère la mémoire si le fichier n'est pas exécutable
            fullpath = NULL;  // Réinitialise fullpath à NULL
            token = strtok(NULL, ":");  // Passe au token suivant
        }
        else
            break;  // Sort de la boucle si un fichier exécutable est trouvé
    }
    free(path_copy);  // Libère la mémoire allouée pour path_copy
    return (fullpath);  // Retourne le chemin complet trouvé ou NULL
}
