#include "mercy.h"
#include "functions.h"
#include "simple_shell.h"

/**
 * environ_key - fetches the variables for the environment
 * @key: pointer to the var
 * @bii: struct ptr
 * Return: value of the variables
 */

char environ_key(char *key, _mn *bii)
{
	int x;
	int len = 0;

	if (key == NULL || bii->env == NULL)
		return (NULL);
	len = str_len(key);
	for (x = 0; bii->env[x]; x++)
	{
		if (str_compare(key, bii->env[x], len) &&
		bii->env[x][len] == '=')
		{
			return (bii->env[x] + len + 1);
		}
	}
	return (NULL);
}

/**
 * print_env - displays the current var
 * @bii: struct ptr
 * Return: nothing
 */

void print_env(_mn *bii)
{
	int x;
	
	for (x = 0; bii->env[x]; x++)
	{
		_print(bii->env[x]);
		_print("\n");
	}
}

/**
 * environ_set - overrides the variables in the environment
 * @key: variable pointer
 * @bii: struct pointer
 * Return: 1 if successful
 */

int environ_set(char *key, char *var, _mn *bii)
{
	int x;
	int len = 0;
	int fresh = 1;

	if (key == NULL || var == NULL || bii->env == NULL)
		return (1);
	len = str_lenth(key);
	for (x = 0; bii->env[x]; x++)
	{
		if (str_compare(key, bii->env[x], len) &&
		bii->env[x][len] == '=')
		{
			fresh = 0;
			free(bii->env[x]);
			break;
		}
	}
	bii->env[x] = str_concat(str_duplicate(key), "=");
	bii->env[x] = str_concat(bii->env[x], var);
	if (fresh)
	{
		bii->env[x + 1] = NULL;
	}
	return (0);
}

/**
 * environ_del - deletes a var from the environment
 * @key: pointer to the var
 * @bii: struct pointer
 * Return: 1 if successful
 */

int environ_del(char *key, _mn *bii)
{
	int x;
	int len = 0;


