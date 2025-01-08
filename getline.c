#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * _getline - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *fp)
{
    char *line;    // Déclare un pointeur pour stocker la ligne lue
    ssize_t read;  // Déclare une variable pour stocker le nombre de caractères lus
    size_t len;    // Déclare une variable pour stocker la longueur de la ligne

    line = NULL;   // Initialise line à NULL
    len = 0;       // Initialise len à 0
    read = getline(&line, &len, fp);  // Lit une ligne depuis fp et la stocke dans line
    if (read == -1)  // Si la lecture a échoué (fin de fichier ou erreur)
    {
        free(line);  // Libère la mémoire allouée pour line
        exit(EXIT_SUCCESS);  // Quitte le programme avec un statut de succès
    }

    return (line);  // Retourne la ligne lue
}
