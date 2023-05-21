#ifndef MERCY_H
#define MERCY_H



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



#include "data_handling.h"
#include "function.h"
#include "simple_shell.h"

#define CD_HELP_INFO

#define EXIT_HELP_INFO

#define ENVIRONMENT_HELP_INFO

#define SETENV_HELP_INFO

#define UNSETENV_HELP_INFO

#define HELP_INFO_SEARCH

#endif
