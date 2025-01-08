#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
    char *line, *path, *fullpath;  // Déclare des pointeurs pour stocker la ligne d'entrée, le chemin et le chemin complet
    char **tokens;  // Déclare un pointeur vers un tableau de chaînes pour stocker les tokens
    int flag, builtin_status, child_status;  // Déclare des variables pour les statuts et les drapeaux
    struct stat buf;  // Déclare une structure stat pour les informations de fichier

    while (TRUE)  // Boucle principale du shell
    {
        prompt(STDIN_FILENO, buf);  // Affiche le prompt
        line = _getline(stdin);  // Lit une ligne d'entrée
        if (_strcmp(line, "\n", 1) == 0)  // Si la ligne est vide (juste un retour à la ligne)
        {
            free(line);  // Libère la mémoire allouée pour la ligne
            continue;  // Passe à l'itération suivante de la boucle
        }
        tokens = tokenizer(line);  // Tokenize la ligne d'entrée
        if (tokens[0] == NULL)  // Si aucun token n'a été trouvé
            continue;  // Passe à l'itération suivante de la boucle
        builtin_status = builtin_execute(tokens);  // Exécute la commande builtin si c'en est une
        if (builtin_status == 0 || builtin_status == -1)  // Si c'était une commande builtin ou s'il y a eu une erreur
        {
            free(tokens);  // Libère la mémoire allouée pour les tokens
            free(line);  // Libère la mémoire allouée pour la ligne
        }
        if (builtin_status == 0)  // Si c'était une commande builtin exécutée avec succès
            continue;  // Passe à l'itération suivante de la boucle
        if (builtin_status == -1)  // Si une erreur s'est produite lors de l'exécution de la commande builtin
            _exit(EXIT_SUCCESS);  // Quitte le programme
        flag = 0;  // Réinitialise le drapeau
        path = _getenv("PATH");  // Obtient la variable d'environnement PATH
        fullpath = _which(tokens[0], fullpath, path);  // Cherche le chemin complet de la commande
        if (fullpath == NULL)  // Si le chemin complet n'a pas été trouvé
            fullpath = tokens[0];  // Utilise le premier token comme chemin
        else
            flag = 1;  // Indique que fullpath a été alloué dynamiquement
        child_status = child(fullpath, tokens);  // Exécute la commande dans un processus enfant
        if (child_status == -1)  // Si l'exécution a échoué
            errors(2);  // Affiche une erreur
        free_all(tokens, path, line, fullpath, flag);  // Libère toute la mémoire allouée
    }
    return (0);  // Retourne 0 pour indiquer une exécution réussie
}
