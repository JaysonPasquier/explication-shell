#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
**builtin_execute - executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_execute(char **tokens)
{
    int status;  // Déclare une variable pour stocker le statut de retour
    unsigned int length;  // Déclare une variable pour la longueur
    unsigned int num;  // Déclare une variable pour le nombre de built-ins
    unsigned int i;  // Déclare une variable pour l'itération

    built_s builtin[] = {  // Définit un tableau de structures built_s
        {"exit", shell_exit},  // Ajoute la commande "exit" et sa fonction associée
        {"env", shell_env},  // Ajoute la commande "env" et sa fonction associée
        {NULL, NULL}  // Termine le tableau avec des valeurs NULL
    };

    if (tokens[0] == NULL)  // Vérifie si le premier token est NULL
        return (1);  // Retourne 1 si aucun token n'est présent

    length = _strlen(tokens[0]);  // Obtient la longueur du premier token

    num = shell_num_builtins(builtin);  // Obtient le nombre de built-ins
    for (i = 0; i < num; i++)  // Boucle à travers tous les built-ins
    {
        if (_strcmp(tokens[0], builtin[i].name, length) == 0)  // Compare le token avec le nom du built-in
        {
            status = (builtin[i].p)();  // Exécute la fonction associée au built-in
            return (status);  // Retourne le statut de la fonction exécutée
        }
    }
    return (1);  // Retourne 1 si aucun built-in n'a été trouvé
}

/**
**shell_num_builtins - this check num built-ins
**@builtin: takes the builtin to be counted
**Return: num of built-ins
**/

int shell_num_builtins(built_s builtin[])
{
    unsigned int i;  // Déclare une variable pour l'itération

    i = 0;  // Initialise i à 0
    while (builtin[i].name != NULL)  // Boucle tant que le nom du built-in n'est pas NULL
        i++;  // Incrémente i

    return (i);  // Retourne le nombre de built-ins
}
