#ifndef ALX_H
#define ALX_H

/**
 *  it  cont all the function and proto types
 * File drp: Contains macros, func prototypes and structers
 *
 * COMMAND _PROMPT - it is the promptent at the beging of the page
 */


/*File inclusion*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>

#define COMMAND_PROMPT "welcome back to alx"

#define UNUSED __attribute__((unused))

#define B_SIZ 1024

#include "data_handling.h"

#include "builtins.h"

#include "func_library.h"

#include "simple_shell.h"


/* Help information display macros */

#define CD_HELP_INFO "cd=\n"\

#define EXIT_HELP_INFO "exit=\n"\

#define ENVIRONMENT_HELP_INFO "env=\n"\

#define SETENV_HELP_INFO "setenv=\n"\

#define UNSETENV_HELP_INFO "unsetenv=\n"\

#define HELP_INFO_SEARCH "help=\n"\


#endif
