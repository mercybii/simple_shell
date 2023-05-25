#include "alx.h"

/**
 * main - main shell program
 * @ac: number of arguments
 * @av: cl arguments
 * @env: variables in the program environment
 * Return: 0 if successful
 */

int main (int ac, char *av[], char *env[])
{
	_mn file_stat = {NULL}, *bii = &file_stat;
	char *prompt = "";

	lion(bii, ac, av, env);

	signal(SIGINT, ctrl_c_hndl);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && ac == 1)
	{
		errno = 2;
		prompt = COMMAND_PROMPT;
	}
	errno = 0;
	manu(prompt, bii);
	return (0);
}

/**
 * ctrl_c_hndl - this code will print out the prompted command
 * @UNUSED: Pototype variable
 */

void ctrl_c_hndl(int opr UNUSED)
{
	_print("\n");
	_print(COMMAND_PROMPT);
}

/**
 * lion - starts the data structure
 * @bii: struct pointer
 * @av: pointer to the input
 * @ac: number of arguments
 * @env: the environment variables
 */

void lion(_mn @bii, int ac, char *av[], char **env)
{
	int x = 0;

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
			_print(bii->a);
			_print(": 0 - not executable");
			_print(av[1]);
			_print("\n");
			exit(127);
		}
	}
	bii->f = NULL;
	bii->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; x++)
		{
			bii->env[x] = str_duplicate(env[x]);
		}
	}
	bii->env[x] = NULL;
	env = bii->env;

