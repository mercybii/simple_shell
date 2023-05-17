#include "functions.h"
#include "mercy.h"
#include "simple_shell.h"

/**
 * _alias - controls the addition or removal of aliases
 * @bii: struct pointer
 * @alias: variable to the output
 * Return: 0 on success
 */

int _alias(_mn *bii, char *alias)
{
	int x;
	int y;
	char buffer[250] = {'\0'};
	int len;

	if (bii->h)
	{
		len = str_length(alias);
		for (x = 0; bii->h[x]; x++)
		{
			if (!alias || (str_compare(bii->[x], alias, len) &&
			bii->h[x][len] == '='))
			{
				for (y = 0; bii->h[x][y]; y++)
				{
					buffer[y] = bii->h[x][y];
					if (bii->h[x][y] == '=')
						break;
				}
				buffer[y + 1] = '\0';
				add_buf(buffer, "'");
				add_buf(buffer, bii->h[x] + y + 1);
				add_buf(buffer, "'\n");
				_print(buffer);
			}
		}
	}
	return (0);
}

/**
 * get_alias - controls addition and removal of aliases
 * @bii: struct pointer
 * @var: name of variable
 * Return: 0 on success
 */

char *get_alias(_mn *bii, char *var)
{
	int x;
	int len;

	if (var == NULL || bii->h == NULL)
		return (NULL);
	len = str_length(var);
	for (x = 0; bii->h[x]; x++)
	{
		if (str_compare(name, bii->h[x], len)
		&& bii->h[x][len] == '=')
		{
			return (bii->h[x] + len + 1);
		}
	}
	return (NULL);
}

/**
 * set_alias - controls the addition and removal of aliases
 * @bii: struct pointer
 * @string: assigns the variable some value
 * Return: 0 on success
 */

int set_alias(char *string, _mn *bii)
{
	int x;
	int y;
	char buffer[250] = {'0'};
	char *holder = NULL;

	if (string == NULL || bii->h == NULL)
		return (1);

	for (x = 0; string[x]; x++)
		if (string[x] != '=')
			buffer[x] = string[x];
		else
		{
			holder = get_alias(bii, string + x + 1);
			break;
		}
	for (y = 0; bii->h[y]; y++)
		if (str_compare(buffer, bii->h[y], x)
		&& bii->h[y][x] == '=')
		{
			free(bii->h[y]);
			break;
		}
	if (holder)
	{
		add_buf(buffer, "=");
		add_buf(buffer, holder);
		bii->h[y] = str_duplicate(buffer);
	}
	else
		bii->h[y] = str_duplicate(string);
	return (0);
}
