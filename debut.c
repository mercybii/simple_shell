#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"


/**
 * main - it is the main Entry point
 *
 * @ac: number of  arguments
 * @av: command line argument
 * @ev: Enviroment variables
 *
 * Return: 0 when successfull
 */

int main(int ac, char *av[], char *ev[])
{
	_mn file_stat = {NULL}, *bii = &file_stat;
	char *promp = "";/*structure declaration*/

	lion(bii. ac, av, ev);

	signal(SIGINT, ctrl_c_hndl); /*ctrl+c*/


	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && ac == 1)
	{

		errno = 2;
	prompt = COMMAND_PROMPT;
	}
	errno = 0;

	tina(prompt, bii);/*display prompt*/

	return (0);

}

/**
 * ctrl_c_hndl - function that print the CMD PROMPT
 *
 * @UNUSED: option of the prototype
 *
 */

void ctrl_c_hndl(int opr UNUSED)
{
	_print("\n");
	_print(COMMAND_PROMPT);
	/* Display promp when input */

}


/**
 * lion - initialize the struture
 *
 * @bii: point to struct data
 * @av: array pointer to user input
 * @ev: is the variable
 * @ac: arguments for the CLI
 *
 */

void lion(_mn *bii, int ac, char *av[], char **ev)
{
	int k = 0;

	bii->a = av[0];
	bii->b = NULL;
	bii->c = NULL;
	bii->d = 0;

	if (ac == 1)
		bii->e = STDIN_FILENO;
	else
	{
		bii->e = open(av[1], O_RDONLY);
		if (bii->e == -1)
		{
			_printe(bii->a);
			_printe(": 0: can not open");
			_printe(av[1]);
			_printe("\n");
			exit(127);
		}
	}
	/*tokenized input*/

	bii->f = NULL;
	bii->env = malloc(sizeof(char *) * 30);
	if (ev)
	{
		for (; ev[k]; k++)
		{
			bii->ev[k] = ster_duplicate(env[k]);
		}
	}
	bii->ev[k] = NULL;
	ev = bii->ev;

	bii->h = malloc(sizeof(char *) * 50);
	for (k = 0; k < 20; k++)
	{
		bii->h[k] = NULL;
	}
}

/**
 * tina - read and exectute user input
 *
 * @prompt: point to shell prompt
 * @bii: Apointer to struct
 *
 */

void tina(char *prompt, mn *bii)
{
	int error = 0;
	int string = 0;

	while (++(bii->d))
	{
		_print(prompt);
		error = string = _getline(bii);

		if (error == EOF)
		{
			free_all_data(bii);
			exit(errno);
		}
		if (string >= 1)
		{
			alias_exp(bii);
			var_exp(bii);
			_token(bii);

			if (bii->f[0])
			{
				error = _execve(bii);
					if (error != 0)
						_print_error(error, bii);
			}
					free_recurrent_date(bii);
		}
	}
}





