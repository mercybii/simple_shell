#include "alx.h"

/**
 * _token - A func that splits strings using delimiter
 *
 * @bii: a pointer to struct
 *
 * Return: Tokens
 */


void _token(_mn *bii)
{
char *del = " \t";
int i, j, counter = 2, length;

length = str_length(bii->b);
if (length)
{
if (bii->b[length - 1] == '\n')
bii->b[length - 1] = '\0';
}

for (i = 0; bii->b[i]; i++)
{
for (j = 0; del[j]; j++)
{
if (bii->b[i] == del[j])
counter++;
}
}

bii->f = malloc(counter *sizeof(char *));
if (bii->f == NULL)
{
perror(bii->a);
exit(errno);
}
i = 0;
bii->f[i] = str_duplicate(_strtok(bii->b, del));
bii->c = str_duplicate(bii->f[0]);
while (bii->f[i++])
{
bii->f[i] = str_duplicate(_strtok(NULL, del));
	}
}
