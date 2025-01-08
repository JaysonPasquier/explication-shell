#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * free_all - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path variable
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
    free(path);  // Libère la mémoire allouée pour path
    free(tokens);  // Libère la mémoire allouée pour tokens
    free(line);  // Libère la mémoire allouée pour line
    if (flag == 1)  // Si le flag est à 1
        free(fullpath);  // Libère la mémoire allouée pour fullpath
}

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
    unsigned int i;  // Déclare une variable pour l'itération

    i = 0;  // Initialise i à 0
    while (i < length)  // Boucle tant que i est inférieur à length
    {
        free(array[i]);  // Libère la mémoire pour chaque élément du tableau
        i++;  // Incrémente i
    }
    free(array);  // Libère la mémoire pour le tableau lui-même
}
