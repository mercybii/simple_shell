#define BII_H
#ifndef BII_H


/**
 * function prototypes and structers
 *
 */

/**
 * header files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>

#define UNUSED __attribute__((unused))
#define COMMAND_PROMPT "HELLO WORLD "


#define B_SIZ 1024


#include "data_handling.h" /* include struters */

#include "builtins.h" /* include builtins */

#include "func_library.h" /*simple_shell functions*/

#define CD_HELP_INFO

#define EXIT_HELP_INFO

#define ENVIRONMENT_HELP_INFO

#define SETENV_HELP_INFO

#define UNSETENV_HELP_INFO

#define HELP_INFO_SEARCH

#endif 