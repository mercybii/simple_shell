#include "alx.h"


/**
 * blt_in_lst - is the exacitable builtin programs
 *
 * @bii: a pointer to struct
 *
 * Return: Return a function value, returns -1 when otherwisw
 **/

int blt_in_lst(_mn *bii)

{

int kay;
builtins options[] =

{
{"exit", blt_in_ext},
{"help", blt_in_hlp},
{"cd", blt_in_cd},
{"alias", blt_in_alias},
{"env", blt_in_env},
{"setenv", blt_set_env},
{"unsetenv", blt_in_unset_env},
{NULL, NULL}
};

	/*the structure*/

for (kay = 0; options[kay].builtin != NULL; kay++)
{
if (str_compare(options[kay].builtin, bii->c, 0))
{
			/* execute a function */

return (options[kay].function(bii));
}
}
return (-1);
}

