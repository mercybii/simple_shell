#include "alx.h"


/**
 * blt_in_lst - a program that execute builtin
 *
 * @bii: a pointer to struct
 *
 * Return: Return a function value,otherwise returns -1.
 **/

int blt_in_lst(_mn *bii)
{
int j;
builtins options[] = {
{"exit", blt_in_ext},
{"help", blt_in_hlp},
{"cd", blt_in_cd},
{"alias", blt_in_alias},
{"env", blt_in_env},
{"setenv", blt_set_env},
{"unsetenv", blt_in_unset_env},
{NULL, NULL}
};


for (j = 0; options[j].builtin != NULL; j++)
{
if (str_compare(options[j].builtin, bii->c, 0))
{


return (options[j].function(bii));/* execute a function */
}
}
return (-1);
}

