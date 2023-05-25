#include "alx.h"

/**
 * str_length - returns the length of a string.
 *
 * @string: pointer to string.
 *
 * Return: length of string.
 */

int str_length(char *string)
{
int len = 0;

if (string == NULL)
return (0);

while (string[len++] != '\0')
{
}
return (--len);
}


/**
 * str_duplicate - duplicates an string
 *
 * @string: String to be copied
 *
 * Return: pointer to the array
 */

char *str_duplicate(char *string)
{
char *res;
int len, i;

if (string == NULL)
return (NULL);

len = str_length(string) + 1;

res = malloc(sizeof(char) * len);

if (res == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (i = 0; i < len ; i++)
{
res[i] = string[i];
}

return (res);
}


/**
 * str_compare - Compare two strings
 *
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 *
 * Return: 1 if the strings are equals,0 if the strings are different
 */

int str_compare(char *string1, char *string2, int number)
{
int iterator;

if (string1 == NULL && string2 == NULL)
return (1);

if (string1 == NULL || string2 == NULL)
return (0);

if (number == 0)
{
if (str_length(string1) != str_length(string2))
return (0);
for (iterator = 0; string1[iterator]; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
else
{
for (iterator = 0; iterator < number ; iterator++)
{
if (string1[iterator] != string2[iterator])
return (0);
}
return (1);
}
}


/**
 * str_concat - concatenates two strings
 *
 * @string1: String to be concatenated
 * @string2: String to be concatenated
 *
 * Return: pointer to the array
 */

char *str_concat(char *string1, char *string2)
{
char *res;
int length1 = 0, length2 = 0;

if (string1 == NULL)
string1 = "";
length1 = str_length(string1);

if (string2 == NULL)
string2 = "";
length2 = str_length(string2);

res = malloc(sizeof(char) * (length1 + length2 + 1));
if (res == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}


for (length1 = 0; string1[length1] != '\0'; length1++)
res[length1] = string1[length1];
free(string1);

for (length2 = 0; string2[length2] != '\0'; length2++)
{
res[length1] = string2[length2];
length1++;
}

res[length1] = '\0';
return (res);
}


/**
 * str_reverse - reverses a string.
 *
 * @string: pointer to string.
 *
 * Return: void.
 */

void str_reverse(char *string)
{

int i = 0, length = str_length(string) - 1;
char hold;

while (i < length)
{
hold = string[i];
string[i++] = string[length];
string[length--] = hold;
}
}

