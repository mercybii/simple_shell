#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


int prog_fnd(_mn *bii);
char **_tok(_mn *bii);
int blt_in_lst(_mn *bii);
void _token(_mn *bii);
void alias_exp(_mn *bii);
int lgc_ops(char *array[], int k, char array[]);
void lion(_mn *bii, int ac, char *av[], char **ev);
void tina(char *prompt, _mn *bii);
char *get_alias(_mn *bii, char *alias);
void ctrl_c(int i UNUSED);
void var_exp(_mn *bii);
int add_buf(char *buf, char *add);
int _execve(_mn *bii);
int _alias(_mn *bii, char *alias);
int set_alias(char *string, _mn *bii);

#endif
