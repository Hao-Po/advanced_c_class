#ifndef __MAIN__
#define __MAIN__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

typedef char my_int[MAX];

void my_add(my_int *sum, my_int *num_one, my_int *num_two);
void my_number_print(my_int *input);
void trans_from_string(my_int *num, char *user_input);

#endif