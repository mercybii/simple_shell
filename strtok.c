#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"

/**
 * _strtok - string that separeate using delimiter
 *
 * @line: pointing to the array
 * @delim: sepating of strings
 *
 * Return: pointer to the token
 */

char *_strtok(char *line, char *delim)
{
	int manu;
	static char *j;
	char *copyj;

	if (line != NULL)
		j = line;

	for (; *j != '\0'; j++)
	{
		for (manu = 0; delim[manu] != '\0'; manu++)
	{
		if (*j == delim[manu])
			break;
	}
	if (delim[manu] == '\0')
		break;
	}
	copyj = j;
	if (*copyj == '\0')
		return (NULL);

	for (; *j != '\0'; j++)
	{
		for (manu = 0; delim[manu] != '\0'; manu++)
		{
			if (*j == delim[manu])
					{
					*j = '\0';
					j++;
					return (copyj);
					}
		}
	}
	return (copyj);
}
