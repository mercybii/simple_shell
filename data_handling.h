#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * struct info- is the program structures
 *
 * @a: is the  executable exacutables files
 * @b: pointer fot the getline structures
 * @c: is the firest command line typed by the user
 * @d: they are exacutable comands
 * @e: input of commands for file discripter
 * @f: pointer to array of tokenized input
 * @env: copy of the environ
 * @h: array of pointers with aliases.
 */
typedef struct file
{
char *a;
char *b;
char *c;
int d;
int e;
char **f;
char **env;
char **h;
} _mn;

/**
 * struct builtins - buildins structs
 *
 * @builtins: they are all the functions
 *
 * @function: the associated function to be called for each builtin
 *
 */
typedef struct builtins
{

char *builtin;

int (*function)(_mn *bii);

} builtins;

#endif 

