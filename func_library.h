#ifndef FUNC_LIBRARY_H
#define FUNC_LIBRARY_H


void _print(const char *string);
int _getline(_mn *bii);
char *_strtok(char *line, char *delim);
void free_array_of_pointers(char **directories);
void free_recurrent_data(_mn *bii);
void free_all_data(_mn *bii);
char *env_get_key(char *name, _mn *bii);
int env_set_key(char *key, char *value, _mn *bii);
int env_remove_key(char *key, _mn *bii);
void print_environ(_mn *bii);
int _print_error(int errorcode, _mn *bii);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
void _print(const char *string);
int p_alias(_mn *bii, char *alias);

#endif
