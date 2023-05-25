#include "alx.h"


/**
 * blt_in_ext - A func that quits the shell program
 *
 * @bii: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_ext(_mn *bii)
{
int i;

if (bii->f[1] != NULL)
{
/*Check argument data type*/
for (i = 0; bii->f[1][i]; i++)
if ((bii->f[1][i] < '0' || bii->f[1][i] > '9')
&& bii->f[1][i] != '+')
{
/*For non-numeric args*/
errno = 2;
return (2);
}
errno = _atoi(bii->f[1]);
}
free_all_data(bii);
exit(errno);
}


/**
 * blt_in_cd - A func that changes current dir
 * @bii: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_cd(_mn *bii)
{
char *dir_home = env_get_key("HOME", bii), *dir_old = NULL;
char old_dir[128] = {0};
int error_code = 0;

if (bii->f[1])
{
if (str_compare(bii->f[1], "-", 0))
{
dir_old = env_get_key("OLDPWD", bii);
if (dir_old)
error_code = st_wk_dir(bii, dir_old);
_print(env_get_key("PWD", bii));
_print("\n");

return (error_code);
}
else
{
return (st_wk_dir(bii, bii->f[1]));
}
}
else
{
if (!dir_home)
dir_home = getcwd(old_dir, 128);

return (st_wk_dir(bii, dir_home));
}
return (0);
}


/**
 * st_wk_dir - Sets PWD
 * @bii: A pointer to struct
 * @new_dir: A pointer to the path of new_dir
 *
 * Return: 0 if successfull
 */


int st_wk_dir(_mn *bii, char *new_dir)
{
char old_dir[128] = {0};
int err_code = 0;

getcwd(old_dir, 128);

if (!str_compare(old_dir, new_dir, 0))

{
err_code = chdir(new_dir);
if (err_code == -1)
{
errno = 2;
return (3);
}
env_set_key("PWD", new_dir, bii);
}
env_set_key("OLDPWD", old_dir, bii);
return (0);
}


/**
 * blt_in_hlp - A func that displays env variables
 * @bii: A pointer to struct
 *
 * Return: 0 if successfull
 */


int blt_in_hlp(_mn *bii)
{
int i, length = 0;
char *van[6] = {NULL};

van[0] = HELP_INFO_SEARCH;
if (bii->f[1] == NULL)
{
_print(van[0] + 6);
return (1);
}
if (bii->f[2] != NULL)
{
errno = E2BIG;
perror(bii->c);
return (5);
}
van[1] = EXIT_HELP_INFO;
van[2] = ENVIRONMENT_HELP_INFO;
van[3] = SETENV_HELP_INFO;
van[4] = UNSETENV_HELP_INFO;
van[5] = CD_HELP_INFO;

for (i = 0; van[i]; i++)
{
length = str_length(bii->f[1]);
if (str_compare(bii->f[1], van[i], length))
{
_print(van[i] + length + 1);
return (1);
}
}
errno = EINVAL;
perror(bii->c);
return (0);
}


/**
 * blt_in_alias - A func that sets aliases
 * @bii: A pointer to struct
 *
 * Return: 0 for successfull code
 */


int blt_in_alias(_mn *bii)
{
int i = 0;

/*print env variables*/
if (bii->f[1] == NULL)
return (p_alias(bii, NULL));

while (bii->f[++i])
{
/*Set env variables*/
if (count_characters(bii->f[i], "="))
set_alias(bii->f[i], bii);
else
p_alias(bii, bii->f[i]);
}

return (0);
}

