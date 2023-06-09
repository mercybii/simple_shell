#include "alx.h"

/**
 * long_to_string - Converts numbers to strings
 *
 * @number: Number to be convetrted
 * @string: A buffer that saves number
 * @base: Base to be convert the number to
 *
 * Return: Void
 */


void long_to_string(long number, char *string, int base)
{
int start = 0, inNegative = 0;
long cociente = number;
char letters[] = {"0123456789abcdef"};

if (cociente == 0)
string[start++] = '0';

if (string[0] == '-')
inNegative = 1;

while (cociente)
{
if (cociente < 0)
string[start++] = letters[-(cociente % base)];
else
string[start++] = letters[cociente % base];
cociente /= base;
}
if (inNegative)
string[start++] = '-';

string[start] = '\0';
str_reverse(string);
}


/**
 * _atoi - Numeric string conveter
 * @s: pointer to string to be converted
 *
 * Return: String integer
 */


int _atoi(char *s)
{
int k = 1;
unsigned int number = 0;

while (!('0' <= *s && *s <= '9') && *s != '\0')
{
if (*s == '-')
k *= -1;
if (*s == '+')
k *= +1;
s++;
}
while ('0' <= *s && *s <= '9' && *s != '\0')
{

number = (number * 10) + (*s - '0');
s++;
}
return (number *k);
}


/**
 * count_characters - Count string coincidence
 *
 * @string: pointer to str to be converted
 * @character: string with char
 *
 * Return: int of string or 0.
 */


int count_characters(char *string, char *character)
{
int i = 0, counter = 0;

for (; string[i]; i++)
{
if (string[i] == character[0])
counter++;
}
return (counter);
}
