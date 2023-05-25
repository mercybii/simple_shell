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
int i;

if (string1 == NULL && string2 == NULL)
return (1);

if (string1 == NULL || string2 == NULL)
return (0);

if (number == 0)
{
if (str_length(string1) != str_length(string2))
return (0);
for (i = 0; string1[i]; i++)
{
if (string1[i] != string2[i])
return (0);
}
return (1);
}
else
{
for (i = 0; i < number ; i++)
{
if (string1[i] != string2[i])
return (0);
}
return (1);
}
}


/**
 * str_concat - concatenates two strings.
 *
 * @string1: String to be concatenated
 * @string2: String to be concatenated
 *
 * Return: pointer to the array
 */

char *str_concat(char *string1, char *string2)
{
char *total;
int len1 = 0, len2 = 0;

if (string1 == NULL)
string1 = "";
len1 = str_length(string1);

if (string2 == NULL)
string2 = "";
len2 = str_length(string2);

total = malloc(sizeof(char) * (len1 + len2 + 1));
if (total == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}

	/* copy of string1 */
for (len1 = 0; string1[len1] != '\0'; len1++)
total[len1] = string1[len1];
free(string1);

for (len2 = 0; string2[len2] != '\0'; len2++)
{
total[len1] = string2[len2];
len1++;
}

total[len1] = '\0';
return (total);
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

int bii = 0, len = str_length(string) - 1;
char hold;

while (bii < len)
{
hold = string[bii];
string[bii++] = string[len];
string[len--] = hold;
}
}

