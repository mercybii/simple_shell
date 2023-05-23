#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {

	char *x;
        char *y;
        char *z;
        int *a;
         int *b;
         char **f;
         char **ev;
         char **h;
}_mn;

int _printe(const char *j);
int _getline(_mn *bii);
int environ_set(const char *key, const char *value, _mn *bii);
int environ_del(const char *key, _mn *bii);
int _print(const char *string);
int _print_error(int errorcode, _mn *bii);
int str_length(const char *string);
int str_compare(const char *string1, const char *string2, int number);
int _atoi(const char *s);
int count_characters(char *string, char *character);
char *_strtok(char *line, char *delim);
char *environ_key(char *name, _mn *bii);
char *str_duplicate(char *string);
char *str_compare2(char *string1, char *string2);
void long_to_string(long number, char *string, int base);
void str_reverse(char *string);
void print_env(_mn *bii);
void free_all_data(_mn *bii);
void free_recurrent_data(_mn *bii);
void free_array_of_pointer(char **directories);

#endif

