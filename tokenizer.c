#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
    char **tokens;  // Déclare un pointeur vers un tableau de chaînes pour stocker les tokens
    char *token;    // Déclare un pointeur pour stocker chaque token
    unsigned int i; // Déclare un compteur

    tokens = malloc(sizeof(char) * BUFFER);  // Alloue de la mémoire pour le tableau de tokens
    if (tokens == NULL)  // Vérifie si l'allocation a échoué
    {
        errors(3);  // Affiche une erreur (probablement liée à l'allocation de mémoire)
        exit(EXIT_FAILURE);  // Quitte le programme avec un statut d'échec
    }

    token = strtok(str, "\n\t\r ");  // Obtient le premier token en utilisant les délimiteurs spécifiés

    i = 0;  // Initialise le compteur
    while (token != NULL)  // Boucle tant qu'il y a des tokens
    {
        tokens[i] = token;  // Stocke le token dans le tableau
        token = strtok(NULL, "\n\t\r ");  // Obtient le prochain token
        i++;  // Incrémente le compteur
    }

    tokens[i] = NULL;  // Marque la fin du tableau avec NULL

    return (tokens);  // Retourne le tableau de tokens
}
