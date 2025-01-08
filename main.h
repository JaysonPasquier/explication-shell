#ifndef MAIN_H
#define MAIN_H

// Inclusions de bibliothèques standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

// Définitions de constantes
#define BUFFER 1024
#define TRUE 1
#define PROMPT "#cisfun$ "
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

// Déclaration de la variable externe environ
extern char **environ;

// Définition de structures

// Structure pour une liste chaînée de variables
typedef struct list_s
{
    char *value;
    struct list_s *next;
} list_s;

// Structure pour les fonctions builtin
typedef struct built_s
{
    char *name;
    int (*p)(void);
} built_s;

// Déclarations de fonctions

// Fonctions d'interface utilisateur
void prompt(int fd, struct stat buf);
char *_getline(FILE *fp);

// Fonctions de traitement de chaînes
char **tokenizer(char *str);
char *_which(char *command, char *fullpath, char *path);

// Fonctions de gestion des processus
int child(char *fullpath, char **tokens);

// Fonctions de gestion des erreurs
void errors(int error);

// Fonctions utilitaires pour les chaînes
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

// Fonctions builtin du shell
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

// Fonctions de gestion de l'environnement
char *_getenv(const char *name);

// Fonction de libération de mémoire
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);

#endif
