#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


void lion(_mn *bii, int arc, char *av[], char **env);
void manu(char *prompt, _mn *bii);
void ctrl_c_hndl(int opr UNUSED);
int lgc_ops(char *array_commands[], int i, char array_operators[]);
void var_exp(_mn *bii);
void alias_exp(_mn *bii);
int add_buf(char *buffer, char *str_to_add);
void _token(_mn *bii);
int _execve(_mn *bii);
int blt_in_lst(_mn *bii);
int p_alias(_mn *bii, char *alias);
char *alias_get(_mn *bii, char *alias);
int set_alias(char *alias_string, _mn *bii);
char **_tok(_mn *bii);
int prog_fnd(_mn *bii);
int p_alias(_mn *bii, char *alias);

#endif
