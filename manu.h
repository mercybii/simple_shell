#ifndef FUNC_LIBRARY_H
#define FUNC_LIBRARY_H

typedef struct {
    char *a;
    char *b;
    char *c;
    int d;
    int e;
    char **f;
    char **env;
    char **h;
} _st;

typedef struct {
    char *builtin;
    int (*function)(_st *nick);
} builtins;



#endif`
