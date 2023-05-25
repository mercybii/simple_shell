#include "alx.h"

/**
 * main - main shell program
 * @ac: number of arguments
 * @av: cl arguments
 * @env: variables in the program environment
 * Return: 0 if successful
 */

int main(int ac, char *av[], char *env[])
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
	bii->h = malloc(sizeof(char *) * 20);
	for (x = 0; x < 20; x++)
	{
		bii->h[x] = NULL;
	}
}

/**
 * manu - reads and exucutes user input data
 * @prompt: points to the shell
 * @bii: struct pointer
 */

void manu(char *prompt, _mn *bii)
{
	int error_code = 0, string_len = 0;


	while (++(bii->d))
	{
		_print(prompt);
		error_code = string_len = _getline(bii);
		if (error_code == EOF)
		{
			free_all_data(bii);
			exit(errno);
		}
		if (string_len >= 1)
		{
			alias_exp(bii);
			var_exp(bii);
			_token(bii);
			if (bii->f[0])
			{
				error_code = execve(bii);
				if (error_code != 0)
					_print_error(error_code, bii);
			}
			free_reccurent_data(bii);
		}
	}
}

