#include "alx.h"

/**
 * _execve - executes a command.
 * @bii: a pointer to struct
 *
 * Return: 0 if successfull.
 */
int _execve(_mn *bii)
{
int ret = 0, status;
pid_t pidd;

ret = blt_in_lst(bii);
if (ret != -1)/*checks if the cmd is a blt-in*/
return (ret);

ret = prog_fnd(bii);
if (ret)/*checks if cmd is execve file*/
{
return (ret);
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

ret = execve(bii->f[0], bii->f, bii->env);
if (ret == -1)
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

