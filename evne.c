#include "alx.h"

/**
 * _execve - executes a command.
 * @bii: a pointer to struct
 * Return: 0 if successfull.
 */
int _execve(_mn *bii)
{
int retval = 0, status;
pid_t pidd;

retval = blt_in_lst(bii);
if (retval != -1)
return (retval);

retval = prog_fnd(bii);
if (retval)
{
return (retval);
}
else
{
		/* create a child process */
pidd = fork();
if (pidd == -1)
{
perror(bii->c);
exit(EXIT_FAILURE);
}
if (pidd == 0)
{
retval = execve(bii->f[0], bii->f, bii->ev);
if (retval == -1)
perror(bii->c), exit(EXIT_FAILURE);
}
else
{
wait(&status);
if (WIFEXITED(status))
errno = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
errno = 128 + WTERMSIG(status);
}
}
return (0);
}

