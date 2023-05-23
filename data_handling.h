#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * struct liststr - singly linked list
 *
 * @num: the number fild
 * @str : a string
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;

} list_t;


/**
 * struct passinfo - Contains pseudo-arguments to pass into a function,
 *                   allowing uniform prototype for function pointer struct.
 *
 * @ag: A string generated from getline containing arguments.
 * @av: An array of strings that are generated from ag.
 * @path: String path for the current command.
 * @ac: The argument count.
 * @line_count: The error count.
 * @err_num: The error code for exit.
 * @linecount_flag: Line of input when on count.
 * @fname: The program filename.
 * @ev: Copy of environ on local link list.
 * @environ: Custom modified copy of environ from link list environment.
 * @history: The history of the nodes.
 * @alias: The alias node.
 * @ev_changed: Environ when changed.
 * @status: The last exec command when status return.
 * @cmd_buf: Address of pointer to cmd_buf.
 * @cmd_buf_type: The cmd_type.
 * @readfd: Read line input.
 * @histcount: Number count history.
 */


typedef struct passinfo
{
	char *ag;
	char **av;
	char *path;
	int ac;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t  *ev;
	list_t *history;
	list_t *alias;
	char **environ;
	int ev_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;

} info_t;

#define INFO_INIT

{
NULL;
NULL;
NULL;
0;
0;
0;
0;
NULL;
NULL;
NULL;
NULL;
NULL;
0;
0;
NULL;
0;
0;
0;
}
/**
 * struct builtin - cointain string and related function
 * @type: the builtin command flag
 * @func: the function
 */

struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;
