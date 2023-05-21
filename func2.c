#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"


/**
 *
 * _print - writes a strings to the output
 *
 * @string: pointer to the string
 *
 * Return: strings in bytes
 *
 */

int _print(char *string)
{
	return (write(stdout_fileno, string, str_length(string)));

}


