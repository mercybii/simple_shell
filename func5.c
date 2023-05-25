#include "alx.h"

/**
 * free_recurrent_data - free fields needed at each loop
 *
 * @bii: a pointer to struct
 *
 * Return:(void)
 */

void free_recurrent_data(_mn *bii)
{
if (bii->f)
free_array_of_pointers(bii->f);
if (bii->b)
free(bii->b);
if (bii->c)
free(bii->c);

bii->b = NULL;
bii->c = NULL;
bii->f = NULL;
}

/**
 * free_all_data - free field of data
 *
 * @bii: a pointer to struct
 *
 * Return:(void)
 */

void free_all_data(_mn *bii)
{
if (bii->e != 0)
{
if (close(bii->e))
perror(bii->a);
}
free_recurrent_data(bii);
free_array_of_pointers(bii->env);
free_array_of_pointers(bii->h);
}

/**
 * free_array_of_pointers - free a pointer of an array
 *
 * @array: array of pointers
 *
 * Return: (void)
 */

void free_array_of_pointers(char **array)
{
int f;

if (array != NULL)
{
for (f = 0; array[f]; f++)
free(array[f]);

free(array);
array = NULL;
}
}
