#include "main.h"

int main(void)
{
    my_int sum, user_input, user_input_2;
    printf("Please giva a number less than 4: ");
    scanf("%c", &user_input);
    // printf("Please giva another number less than 4: ");
    printf("%c", user_input[2]);
    // my_number_print(user_input);
    return 0;
}

void my_add(char input_1, char inupt_2)
{
}

void my_number_print(char *input)
{
    for (int index = 0; index < sizeof(input); index++)
    {
        printf("%c", *input + index);
    }
}

void trans_from_string(char *user_input)
{
}