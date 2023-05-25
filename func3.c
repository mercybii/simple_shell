#include "alx.h"


/**
 * _strtok - string separation using delimiter.
 * @line: a pointer to an array.
 * @delim: character that separates strings.
 *
 * Return: A pointer to a token.
*/

char *_strtok(char *line, char *delim)
{
int jay;
static char *str;
char *copystr;

if (line != NULL)
str = line;

for (; *str != '\0'; str++)
{
for (jay = 0; delim[jay] != '\0'; jay++)
{
if (*str == delim[jay])
break;
}
if (delim[jay] == '\0')
break;
}
copystr = str;
if (*copystr == '\0')
return (NULL);
for (; *str != '\0'; str++)
{
for (jay = 0; delim[jay] != '\0'; jay++)
{
if (*str == delim[jay])
{
*str = '\0';
str++;
return (copystr);
}
}
}
return (copystr);
}
