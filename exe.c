#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"
#include "builtins.h"

/**
 * -execve - executes a command
 *
 *  @bii: pointer to struct
 *
 *  Return: 0 when successfull
 */

int _execve(_bii *bii)
{
	int retvel = 0;
	int status;
	pid_t ppid;


	retval = blt_in_lst(bii);

	if (retval != -1)
		return (retval);

	retval = prog_find(bii);
	if (retval != -1)
		return (retval);

	retval = prog_fine(bii)
		if (retval)
		{
			return (retval);
		}
		else
		{
			pidd = fork();
			if (pidd == -1)
			{
				perror(bii->c);
				exit(EXIT_FAILURE);
			}
			if (pidd == 0)
			{
				retval = execve(nick->f[0], bii->f, bii->ev);
				if (retval == -1)
					perror(bii->), exit(EXIT_FAILURE);
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					errno = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
						errno = 128 + wtermsig(status)
						}
						return (0);
						}
						
