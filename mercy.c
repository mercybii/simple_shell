#include "alx.h"

/**
 * blt_in_env - displays environment variables
 * @bii: a pointer to struct
 * Return: 0 if sucessful, or otherwise if fails.
 */
int blt_in_env(_mn *bii)
{
int i;
char cpname[50] = {'\0'};
char *var_copy = NULL;

	/* check if it a NULL argument */
if (bii->f[1] == NULL)
print_environ(bii);
else
{
for (i = 0; bii->f[1][i]; i++)
{
if (bii->f[1][i] == '=')
{
var_copy = str_duplicate(env_get_key(cpname, bii));
if (var_copy != NULL)
env_set_key(cpname, bii->f[1] + i + 1, bii);

				/* print the environ */
print_environ(bii);
if (env_get_key(cpname, bii) == NULL)
{
_print(bii->f[1]);
_print("\n");
}
else
{
env_set_key(cpname, var_copy, bii);
free(var_copy);
}
return (0);
}
cpname[i] = bii->f[1][i];
}
errno = 2;
perror(bii->c);
errno = 127;
}
return (0);
}

/**
 * blt_set_env - a function that set env variables.
 * @bii:a pointer to struct.
 * Return: 0 if sucessfull.
 */

int blt_set_env(_mn *bii)
{
if (bii->f[1] == NULL || bii->f[2] == NULL)
return (0);
if (bii->f[3] != NULL)
{
errno = E2BIG;
perror(bii->c);
return (5);
}

env_set_key(bii->f[1], bii->f[2], bii);

return (0);
}

/**
 * blt_in_unset_env - a function that unsets env variables.
 * @bii: a pointer to struct
 * Return: 0 if successfull.
 */
int blt_in_unset_env(_mn *bii)
{
if (bii->f[1] == NULL)
return (0);
if (bii->f[2] != NULL)
{
errno = E2BIG;
perror(bii->c);
return (5);
}
env_remove_key(bii->f[1], bii);

return (0);
}
