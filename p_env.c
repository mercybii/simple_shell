#include "alx.h"


/**
 * env_get_key - A function that gets env variables
 *
 * @key: A pointer to target env variable
 * @bii: A pointer to struct
 *
 * Return: a pointer to the value of env variable
 */


char *env_get_key(char *key, _mn *bii)
{
int i, key_length = 0;

if (key == NULL || bii->ev == NULL)
return (NULL);
key_length = str_length(key);
for (i = 0; bii->ev[i]; i++)
{
if (str_compare(key, bii->ev[i], key_length) &&
bii->ev[i][key_length] == '=')
{
return (bii->ev[i] + key_length + 1);
		}
}
return (NULL);
}
