#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"
/**
 * str_length - return the lrngth of a string.
 *
 * @string: pointer to string
 *
 * Return: length of string
 */

int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')

		return (--length);

}


