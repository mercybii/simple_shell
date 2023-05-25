#include "alx.h"

/**
* _getline - A func that reads user input
*
* @bii: A pointer to struct
*
* Return: The number of user input bytes
*/


int _getline(_mn *bii)
{
char buff[B_SIZ] = {'\0'};
static char *array_commands[10] = {NULL};
static char array_operators[10] = {'\0'};
ssize_t bytes_read, i = 0;

if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
(array_operators[0] == '|' && errno == 0))
{

for (i = 0; array_commands[i]; i++)
{
free(array_commands[i]);
array_commands[i] = NULL;
}

bytes_read = read(bii->e, &buff, B_SIZ - 1);
if (bytes_read == 0)
return (-1);


i = 0;
do {
array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));

i = lgc_ops(array_commands, i, array_operators);
} while (array_commands[i++]);
}

bii->b = array_commands[0];
for (i = 0; array_commands[i]; i++)
{
array_commands[i] = array_commands[i + 1];
array_operators[i] = array_operators[i + 1];
}

return (str_length(bii->b));
}


/**
* lgc_ops - Checks for && and || delimeters
* @array_commands: pointer array to user in command
* @i: Character index of input data
* @array_operators: A pointer array to the logical operatoers delimeter
*
* Return: Index of the last delimeter in the string
*/


int lgc_ops(char *array_commands[], int i, char array_operators[])
{
char *temp = NULL;
int j;


for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
{
if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
{

temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = str_duplicate(array_commands[i]);
array_commands[i + 1] = str_duplicate(temp + j + 2);
i++;
array_operators[i] = '&';
free(temp);
j = 0;
}
if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
{
temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = str_duplicate(array_commands[i]);
array_commands[i + 1] = str_duplicate(temp + j + 2);
i++;
array_operators[i] = '|';
free(temp);
j = 0;
}
}
return (i);
}

