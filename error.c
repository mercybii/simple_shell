#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"

/**
 * _print_error - write the string output
 *
 * @bii: a pointer to struct
 * @errorcode: it is the code with error
 *
 * Return: the number of bytes written
 */

int _print_error(int errorcode, _mn *bii)
{
	char string = {'\0'};

	long_to_string(long) bii->d, string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(bii->a);
		_printe("||");
		_printe(string);
		_printe("||");
		_printe(bii->f[0]);

		if (errorcode == 2)
			_printe("|| no way");

		else
			_printe("|| yes they no way");
		_printe(bii->[1];
				_printe("\n");

				}
				else if (errorcode == 127)
				{
				_printe(bii->a);
				_printe("||");
				_printe(string);
				_print("||");
				_printe(bii->c);
				_printe("|| not found\n");
				}
				else if (errorcode == 125)
				{
				_printe(bii->a);
				_printe("||");
				_printe(string);
				_printe("||");
				_printe(bii->c);
				_printe("|| no permission\n");
				}
				return (0);
}


