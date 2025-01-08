#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
    if (error == 1)  // Si le code d'erreur est 1
    {
        write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));  // Écrit le message d'erreur ERR_FORK sur la sortie d'erreur standard
        perror("Error");  // Affiche un message d'erreur système
    }
    else if (error == 2)  // Si le code d'erreur est 2
    {
        perror("Error");  // Affiche un message d'erreur système
    }
    else if (error == 3)  // Si le code d'erreur est 3
    {
        write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));  // Écrit le message d'erreur ERR_MALLOC sur la sortie d'erreur standard
    }
    else if (error == 4)  // Si le code d'erreur est 4
    {
        write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));  // Écrit le message d'erreur ERR_PATH sur la sortie d'erreur standard
    }
    else  // Si le code d'erreur n'est pas reconnu
    {
        return;  // Retourne sans rien faire
    }
}
