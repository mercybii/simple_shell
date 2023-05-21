#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * struct file  - the structure of the program's data
 *
 * @x: the name for the program's data
 * @y: pointer to the input read for getline
 * @z: pointer to the first command typed by the user
 * @a: number of executed comands
 * @b: file descriptor to the input of commands
 * @f: pointer to array of token input
 * @ev: copy of the environ
 * @h: array of pointer with aliases
 *
 *
 */

typedef struct file
{
	char *x;
	char *y;
	char *z;
	int *a;
	 int *b;
	 char **f;
	 char **ev;
	 char **h;

}
_mn;

/**
 * struct builtins - struct for the builtins
 * @functions: the associate function to be called for each builtins
 *
 */

typedef struct -mn
{
	char *builtins
	int (*functions)(_mn *bii);
} mn;

#endif
