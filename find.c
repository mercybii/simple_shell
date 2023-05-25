#include "alx.h"

int prog_fnd(_mn *bii);
char **_tok(_mn *bii);
int check_file(char *full_path);

/**
 * prog_fnd - find path
 *
 * @bii: a pointer to struct.
 *
 * Return: 0 if successfull.
 */

int prog_fnd(_mn *bii)
{

int i = 0, ret_code = 0;
char **directories;

if (!bii->c)/*Check if input is NULL*/
return (2);
	/*Check if input is '/' || '.'(PATH)*/
if (bii->c[0] == '/' || bii->c[0] == '.')
return (check_file(bii->c));
free(bii->f[0]);/*If not a PATH*/
bii->f[0] = str_concat(str_duplicate("/"), bii->c);
if (!bii->f[0])
return (2);
directories = _tok(bii);
if (!directories || !directories[0])
{
errno = 127;
return (127);
}
for (i = 0; directories[i]; i++)/*Check every dir for X_OK*/
{
directories[i] = str_concat(directories[i], bii->f[0]);
ret_code = check_file(directories[i]);
if (ret_code == 0 || ret_code == 126)
{
errno = 0;/*If file is found*/
free(bii->f[0]);
bii->f[0] = str_duplicate(directories[i]);
free_array_of_pointers(directories);
return (ret_code);/*If file is not found*/
		}
}
free(bii->f[0]);/*Free memory*/
bii->f[0] = NULL;
free_array_of_pointers(directories);
return (ret_code);
}


/**
 * _tok - tokenize the path.
 *
 * @bii: a pointer to struct
 *
 * Return: array of the  path
 */

char **_tok(_mn *bii)
{
int i = 0;
int counter_directories = 2;
char **tokens = NULL;
char *PATH;

PATH = env_get_key("PATH", bii);
if ((PATH == NULL) || PATH[0] == '\0')
{
return (NULL);/*Error statements*/
}

PATH = str_duplicate(PATH);/*Duplicate PATH*/

for (i = 0; PATH[i]; i++)/*Iterate through PATH*/
{
if (PATH[i] == ':')/*Delimeter*/
counter_directories++;
}

tokens = malloc(sizeof(char *) * counter_directories);

i = 0;
tokens[i] = str_duplicate(_strtok(PATH, ":"));
while (tokens[i++])
{
tokens[i] = str_duplicate(_strtok(NULL, ":"));
}
	/*Free memory*/
free(PATH);
PATH = NULL;
return (tokens);

}

/**
 * check_file - checks if executable file exists
 *
 * @full_path: pointer to the full file name
 *
 * Return: 0 on successfull
 */

int check_file(char *full_path)
{
struct stat sb;

if (stat(full_path, &sb) != -1)
{
if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
{
errno = 126;
return (126);
}
return (0);
}
	/*if file does not exist*/
errno = 127;
return (127);
}

