#include "alx.h"


/**
 * env_get_key - A function that gets env variables
 *
 * @key: A pointer to target env variable
 * @bii: A pointer to struct
 *
 * Return: a pointer to the value of env variable
 */


char *env_get_key(char *key, _mn *bii)
{
int i, key_length = 0;

if (key == NULL || bii->env == NULL)
return (NULL);
key_length = str_length(key);
for (i = 0; bii->env[i]; i++)
{
		/*Transverses through the environ*/
if (str_compare(key, bii->env[i], key_length) &&
bii->env[i][key_length] == '=')
{
return (bii->env[i] + key_length + 1);
}
}
return (NULL);
}


/**
 * env_set_key - A func that  overwrites env var
 *
 * @key: A pointer to env var
 * @value: new value
 * @bii: A pointer to struct
 *
 * Return: 1 if the parameters are NULL
 */


int env_set_key(char *key, char *value, _mn *bii)
{
int i, key_length = 0, is_new_key = 1;

if (key == NULL || value == NULL || bii->env == NULL)
return (1);
key_length = str_length(key);
for (i = 0; bii->env[i]; i++)
{
if (str_compare(key, bii->env[i], key_length) &&
bii->env[i][key_length] == '=')
{
is_new_key = 0;
free(bii->env[i]);
break;
}
}
bii->env[i] = str_concat(str_duplicate(key), "=");
bii->env[i] = str_concat(bii->env[i], value);

if (is_new_key)
{
bii->env[i + 1] = NULL;
}
return (0);
}


/**
 * env_remove_key - A func that remove a key from the env
 *
 * @key: A pointer to the key to remove
 * @bii: A pointer to struct
 * Return: 1 if the key was removed
 */


int env_remove_key(char *key, _mn *bii)
{
int i, key_length = 0;

if (key == NULL || bii->env == NULL)
return (0);

	/* obtains the leng of the variable requested */
key_length = str_length(key);

for (i = 0; bii->env[i]; i++)
{
if (str_compare(key, bii->env[i], key_length) &&
bii->env[i][key_length] == '=')
{
			/* if key already exists, remove them */
free(bii->env[i]);

			/* move the others keys one position down */
i++;
for (; bii->env[i]; i++)
{
bii->env[i - 1] = bii->env[i];
}
bii->env[i - 1] = NULL;
return (1);
}
}
return (0);
}


/**
 * print_environ - prints the current env variables
 *
 * @bii: A pointer to struct
 *
 * Return: void
 */


void print_environ(_mn *bii)
{
int j;

for (j = 0; bii->env[j]; j++)
{
_print(bii->env[j]);
_print("\n");
}
}
