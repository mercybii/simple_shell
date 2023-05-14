#ifndef FUNCTION_H
#define FUNCTION_H

int _printe(char *j);
int _getline(_mn *bii);
int env_set_key(char *key, char *value, _mn *bii);
int env_remove_key(char *key, _mn *bii);
int _print(char *string);
int _print_error(int errorcode, _mn *bii);
int str_length(char *string);
int str_compare(char *string1, char *string2, int number);
int _atoi(char *s);
int count_characters(char *string, char *character);
char *_strtok(char *line, char *delim);
char *env_get_key(char *name,_mn *bii);
char *str_duplicate(char *string);
char *str_compare(char *string1, char *'string2);
void long_to_string(long number, char *string, int base);
void str_reverse(char *string);
void print_environ(_mn *bii);
void free_all_data(_mn *bii);
void free_recurrent_data(_mn *bii);
void free_array_of_pointer(char **directories);

#endif

