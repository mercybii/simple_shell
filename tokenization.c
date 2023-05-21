#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"

/**
 * _token - used to separate strings
 * @bii: struct pointer
 * Return: void
 */

void _token(_mn *bii)
{
	char *delim = " \t";
	int a;
	int b;
	int count = 2;
	int len;

	len = str_length(bii->y);
	if (len)
	{
		if (bii->y[len - 1] == '\n')
			bii->y[len - 1] = '\0';
	}
	for (a = 0; bii->y[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (bii->y[a] == delim[b])
				count++;
		}
	}
	bii->f = malloc(count * sizeof(char *));
	if (bii->f == NULL)
	{
		perror(bii->x);
		exit(errno);
	}
	a = 0;
	bii->f[a] = str_duplicate(_strtok(bii->y, delim));
	bii->z = str_duplicate(bii->f[0]);
	while (bii->f[a++])
	{
		bii->f[a] = str_duplicate(_strtok(NULL, delim));
	}
}
