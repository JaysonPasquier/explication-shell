#include "main.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
    unsigned int var_length;
    unsigned int i;

    var_length = _strlen(variable);  // Obtient la longueur de la variable
    if (var_length != length)  // Compare les longueurs
        return (-1);  // Retourne -1 si les longueurs sont différentes

    i = 0;
    while (name[i] != '\0' && variable[i] != '\0')  // Parcourt les deux chaînes
    {
        if (name[i] != variable[i])  // Compare chaque caractère
            return (1);  // Retourne 1 si un caractère est différent
        i++;
    }
    return (0);  // Retourne 0 si les chaînes sont identiques
}

/**
 * _strncmp - compares two strings up to given length
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
    unsigned int i;

    i = 0;
    while (i < length)  // Parcourt les chaînes jusqu'à la longueur spécifiée
    {
        if (name[i] != variable[i])  // Compare chaque caractère
            return (-1);  // Retourne -1 si un caractère est différent
        i++;
    }
    return (1);  // Retourne 1 si les chaînes sont égales jusqu'à la longueur spécifiée
}

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int i;
    int j = _strlen(src);  // Obtient la longueur de la chaîne source

    for (i = 0; i <= j; i++)  // Copie chaque caractère, y compris le caractère nul
        dest[i] = src[i];

    return (dest);  // Retourne le pointeur vers la destination
}

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')  // Compte les caractères jusqu'au caractère nul
        i++;

    return (i);  // Retourne la longueur de la chaîne
}
