#include "alx.h"


/**
 * p_alias - add or remove alias
 * @bii: a pointer to struct
 * @alias: name to  be printed
 *
 * Return: 0 if successfull
 */

int p_alias(_mn *bii, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (bii->h)
	{
		alias_length = str_length(alias);
		for (i = 0; bii->h[i]; i++)
		{
			if (!alias || (str_compare(bii->h[i], alias, alias_length)
				&&	bii->h[i][alias_length] == '='))
			{
				for (j = 0; bii->h[i][j]; j++)
				{
					buffer[j] = bii->h[i][j];
					if (bii->h[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				add_buf(buffer, "'");
				add_buf(buffer, bii->h[i] + j + 1);
				add_buf(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}


/**
 * alias_get - add or remove alias
 * @bii: a pointer to struct.
 * @name: name of the  alias.
 *
 * Return: 0 if successfull.
 */

char *alias_get(_mn *bii, char *name)
{
	int i, alias_length;

	if (name == NULL || bii->h == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; bii->h[i]; i++)
	{
		/* Iterates through the environ and check for coincidence of the varname */
		if (str_compare(name, bii->h[i], alias_length) &&
			bii->h[i][alias_length] == '=')
		{
			return (bii->h[i] + alias_length + 1);
		}
	}

	return (NULL);

}


/**
 * set_alias - add or remove alias
 * @alias_string: set in the alias in the form (name = 'value')
 * @bii: a pointer to struct
 * Return: 0 if successfull.
 */

int set_alias(char *alias_string, _mn *bii)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  bii->h == NULL)
		return (1);

	/* Iterates alias to find = char */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = alias_get(bii, alias_string + i + 1);
			break;
		}

	/* Iterates through the alias list and check for coincidence of the varname */
	for (j = 0; bii->h[j]; j++)
		if (str_compare(buffer, bii->h[j], i) &&
			bii->h[j][i] == '=')
		{
			free(bii->h[j]);
			break;
		}

	/* add the alias */
	if (temp)
	{
		add_buf(buffer, "=");
		add_buf(buffer, temp);
		bii->h[j] = str_duplicate(buffer);
	}
	else
		bii->h[j] = str_duplicate(alias_string);
	return (0);
}
