#ifndef MERCY_H
#define MERCY_H


#include "function.h"
#include "mercy.h"
#include "simple_shell.h"
#include "data_handling.h"


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

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define  BUF_FLUSH -1


#define B_SIZ 1024


#define CMD_NORM
#define CMD_OR
#define CMD_AND
#define CMD_CHAIN


#define CONVERT_LOWERCASE
#define CONVERT_STRTOK


#define HIST_FILE

#define HIST_MAX


#endif
