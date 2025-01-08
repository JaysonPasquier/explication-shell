#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
**shell_exit - exits the shell
**Return: void
**/

int shell_exit(void)
{
    return(-1);  // Retourne -1 pour indiquer que le shell doit se terminer
}


/**
**shell_env - prints environment
**Return: void
**/

int shell_env(void)
{
    unsigned int i;  // Déclare une variable pour l'itération

    i = 0;  // Initialise i à 0
    while (environ[i] != NULL)  // Boucle tant que la variable d'environnement n'est pas NULL
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));  // Écrit la variable d'environnement sur la sortie standard
        write(STDOUT_FILENO, "\n", 1);  // Écrit un retour à la ligne
        i++;  // Incrémente i pour passer à la prochaine variable d'environnement
    }
    return (0);  // Retourne 0 pour indiquer que la fonction s'est terminée avec succès
}
