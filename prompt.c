#include "main.h"  // Inclut le fichier d'en-tête "main.h"

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
**/
void prompt(int fd, struct stat buf)
{
    fstat(fd, &buf);  // Obtient les informations sur le descripteur de fichier

    if (S_ISCHR(buf.st_mode))  // Vérifie si le mode du fichier est un périphérique de caractères (terminal)
        _puts(PROMPT);  // Si c'est le cas, affiche le prompt
}

/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
    unsigned int length;  // Déclare une variable pour stocker la longueur de la chaîne

    length = _strlen(str);  // Obtient la longueur de la chaîne

    write(STDOUT_FILENO, str, length);  // Écrit la chaîne sur la sortie standard
}
