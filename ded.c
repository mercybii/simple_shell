#include "alx.h"

/**
 * main - Entry point of the shell program
 * @ac: Number of CL arguments
 * @av: Command line arguments
 * @env: Environment variables
 *
 * Return: 0 is successfull
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
 * ctrl_c_hndl - A function that prints the CMD PROMPT
 *
 * @UNUSED: option of the prototype
 *
 */

void ctrl_c_hndl(int opr UNUSED)
{

_print("\n");
_print(COMMAND_PROMPT);
}


/**
 * lion - A func that initializes the struct
 * @bii: pointer to struct data
 * @av: Array pointer to user input
 * @env: env variables
 * @ac: Number of arguments for the CLI
 *
 */


void lion(_mn *bii, int ac, char *av[], char **env)
{
int i = 0;

bii->a = av[0];/*hsh*/
bii->b = NULL;/*Read user-input*/
bii->c = NULL;/*First cmd*/
bii->d = 0;/*Number of executed cmd*/

if (ac == 1)/*hsh*/
bii->e = STDIN_FILENO;/*File descriptors*/
else
{
bii->e = open(av[1], O_RDONLY);
if (bii->e == -1)
{
printf("%s", bii->a);
_print(": 0: dont open ");
_print(av[1]);
_print("\n");
exit(127);
}
}
bii->f = NULL;/*Tokenized input*/
bii->env = malloc(sizeof(char *) * 50);/*Pointer to env*/
if (env)
{
for (; env[i]; i++)/*Duplicate env var(path)*/
{
bii->env[i] = str_duplicate(env[i]);
}
}
bii->env[i] = NULL;
env = bii->env;

bii->h = malloc(sizeof(char *) * 20);
for (i = 0; i < 20; i++)
{
bii->h[i] = NULL;/*Pointer to aliases*/
}
}



/**
 * manu - A func that reads and execute user-input
 * @prompt: A pointer to Shell prompt
 * @bii: A pointer to struct
 *
 */


void manu(char *prompt, _mn *bii)
{
	/*Variable declaration*/
int error_code = 0, string_len = 0;

while (++(bii->d))/*Whenever executing*/
{
_print(prompt);/*Display prompt*/
		/*Read user-input*/
error_code = string_len = _getline(bii);

if (error_code == EOF)/*Check length of cmd*/
{
free_all_data(bii);
exit(errno);
}
if (string_len >= 1)/*If cmd is in range*/
{
alias_exp(bii);/*Execute alias*/
var_exp(bii);/*Execute special char*/
_token(bii);/*Tokenize user-cmd*/
if (bii->f[0])
{
				/*Execute user-cmd*/
error_code = _execve(bii);
if (error_code != 0)
_print_error(error_code, bii);
}
free_recurrent_data(bii);/*free memory*/
}
}
}

