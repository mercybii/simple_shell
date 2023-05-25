#ifndef FUNC_LIBRARY_H
#define FUNC_LIBRARY_H

typedef struct
{
char *a;
char *b;
char *c;
int d;
int e;
char **f;
char **env;
char **h;
} _mn;

typedef struct
{
char *builtin;
int (*function)(_mn *bii);
} builtins;

int _getline(_mn *bii);
char *_strtok(char *line, char *delim);
void free_array_of_pointers(char **directories);
void free_recurrent_data(_mn *bii);
void free_all_data(_mn *bii);
char *env_get_key(char *name, _mn *bii);
int env_set_key(char *key, char *value, _mn *bii);
int env_remove_key(char *key, _mn *bii);
void print_environ(_mn *bii);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, _mn *bii);
int str_length(char *string);

#endif /* FUNC_LIBRARY_H */


