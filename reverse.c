#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"


/**
 * str_reverse - reverses a string.
 * @string: pointer to string.
 * Return: void.
 */

void str_reverse(char *string)
{

	int i = 0, length = str_length(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
