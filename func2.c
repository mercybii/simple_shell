#include "alx.h"


/**
 * _strtok - string separation using delimiter.
 *
 * @line: a pointer to an array.
 * @delim: character that separates strings.
 *
 * Return: A pointer to a token.
*/

char *_strtok(char *line, char *delim)
{
int bii;
static char *str;
char *copystr;

if (line != NULL)
str = line;

for (; *str != '\0'; str++)
{
for (bii = 0; delim[bii] != '\0'; bii++)
{
if (*str == delim[bii])
break;
}
if (delim[bii] == '\0')
break;
}
copystr = str;
if (*copystr == '\0')
return (NULL);
for (; *str != '\0'; str++)
{
for (bii = 0; delim[bii] != '\0'; bii++)
{
if (*str == delim[bii])
{
*str = '\0';
str++;
return (copystr);
}
}
}
return (copystr);
}

