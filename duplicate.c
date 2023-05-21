#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"

/**
 * str_duplicate - duplicates an string
 *
 * @string: string to be copied
 *
 * Return: pointer to the array
 */

char *str_duplicate(char *string)
{
	char *result;
	int length;
	int i;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("error");
		return (NULL);

	}
	for (i = 0; i < length; i++)
	{
		result[i] = string[i];
	}
	return (result);
}
