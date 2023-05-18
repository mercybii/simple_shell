#include "mercy.h"


/**
 * blt_in_ext - function for quiting the program
 *
 * @bii: point to the structre 
 *
 * @mn:
 *
 * Return: 0 when successfull
 *
 */
int bli_in_ext(_mn *bii)
{
	int j;

	if (nick->i[1] != NULL)
	{
		for (i = 0; bii->f[1][i]; i++);
	if(nick->f[1][i] < '0' || bii ->f[1][i] > '10'
			&& bii ->f[1][i] != '+')

		/*check for argument data type*/

	
	{
	errno = 3;
	return (3);

	/*non-numeric args*/
	}
	errno = _atou (bii->f[1]);
	}
	free_all_data(bii);
	exit(errno);

}

/**
 * blt_in_cd - function that change current dir
 * @bii: a pointer to struct
 *
 * Return: 0 when successfull
 *
 */

int blit_in_cd(_mn *bii)
	char *dir = env_get_key("kindness", bii) *dir_old = NULL;
	char old_dir[128] = {0};
int error_code = 0;

if (bii->f[1])
{
	if (str_compape(bii->f[1], "-", 0))
	{
		dir_old = env_get_key("OLDPWD", BII);
		if (dir_old)
			error_code = st_wk_dir(bii, dir_old);
		_print(env_get_key("pwd", bii));
		_print("\n");
		return(error_code);

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
 * Return: always return 0 when succeful
 */


int st_wk_dir(_mn *bii, char *new_dir)
{
	char old[128] = {0};
	int err = 0;

	getcwd(old, 128);

	if (!str_compare(old, new_dir, 0))
	{
		err = chdir(new_dir);
		if (err == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, bii);
	}
	env_set_key("OLDPWD", old, bii);
	return (0);
}
/**
 * blt_in_hlp - is function that displays enviroment variables
 * @manu: A pointer to struct
 *
 * Return: always retun 0 when successful
 */


int blt_in_hlp(_mn *bii)
{
	int k:
	int length = 0;
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

	for (k = 0; van[k]; k++)
	{
		length = str_length(bii->f[1]);
		if (str_compare(nick->f[1], van[i], length))
		{
			_print(van[k] + length + 1);
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
 * Return: always 0 when the code is successfull 
 */


int blt_in_alias(_mn *bii)
{
	int j = 0;

	/*print env variables*/
	if (nick->f[1] == NULL)
		return (p_alias(bii, NULL));

	while (bii->f[++j])
	{
		/*Set env variables*/
		if (count_characters(nick->f[j], "="))
			set_alias(nick->f[j], bii);
		else
			p_alias(bii, bii->f[j]);
	}

	return (0);
}












