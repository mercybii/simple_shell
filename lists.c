#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"

/**
 * builtin_list - executes built in programs
 * @bii: struct pointer
 * Return: value of function or -1
 */

int builtin_list(_mn *bii)
{
	int x;

	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{NULL, NULL}
	};
	for (x = 0; options[x].builtin != NULL; x++)
	{
		if (str_compare(options[x].builtin, bii->c, 0))
		{
			return (options[x].function(bii));
		}
	}
	return (-1);
}

