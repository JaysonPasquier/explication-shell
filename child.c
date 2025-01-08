#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int child(char *fullpath, char **tokens)
{
    pid_t child_pid;  // Déclare une variable pour stocker le PID du processus enfant
    int status;  // Déclare une variable pour stocker le statut de sortie
    int execve_status;  // Déclare une variable pour stocker le statut de execve
    char **envp = environ;  // Copie l'environnement actuel dans envp

    child_pid = fork();  // Crée un nouveau processus
    if (child_pid == -1)  // Vérifie si la création du processus a échoué
    {
        errors(1);  // Appelle la fonction errors avec le code 1
        exit(EXIT_FAILURE);  // Termine le programme avec un code d'échec
    }
    if (child_pid == 0)  // Si c'est le processus enfant
    {
        execve_status = execve(fullpath, tokens, envp);  // Exécute le programme spécifié
        if (execve_status == -1)  // Si l'exécution a échoué
            return (-1);  // Retourne -1 pour indiquer l'échec
    }
    else  // Si c'est le processus parent
        wait(&status);  // Attend que le processus enfant se termine

    return (0);  // Retourne 0 pour indiquer le succès
}
