#include "main.h"

int main(void)
{
    char user_input_num_one[MAX + 1] = {0};
    char user_input_num_two[MAX + 1] = {0};
    my_int num[2], sum;
    my_int *ptr;

    ptr = num;

    printf("Please giva a number less than %d: ", MAX);
    scanf("%s", &user_input_num_one);

    if (strlen(user_input_num_one) > MAX)
    {
        printf("OverFlow!");
        return 1;
    }

    trans_from_string(ptr, user_input_num_one);

    printf("Please giva another number less than %d: ", MAX);
    scanf("%s", &user_input_num_two);

    if (strlen(user_input_num_two) > MAX)
    {
        printf("OverFlow!");
        return 1;
    }

    trans_from_string(ptr + 1, user_input_num_two);
    my_add(&sum, ptr, ptr + 1);

    return 0;
}

void my_add(my_int *sum, my_int *num_one, my_int *num_two)
{
    int carry = 0;
    for (int index = MAX - 1; index > -1; index--)
    {
        if ((*num_one)[index] + (*num_two)[index] + carry - '0' > 57)
        {
            (*sum)[index] = ((*num_one)[index] + (*num_two)[index] + carry - 2 * '0') % 10 + '0';
            carry = 1;
        }
        else
        {
            (*sum)[index] = (*num_one)[index] + (*num_two)[index] + carry - '0';
            carry = 0;
        }
    }

    if (carry)
    {
        printf("OverFlow!");
        return;
    }

    my_number_print(sum);
}

void my_number_print(my_int *input)
{
    int First = 1;
    printf("The add result: ");
    for (int index = 0; index < MAX; index++)
    {
        if (First && (*input)[index] == '0')
        {
            continue;
        }
        printf("%c", (*input)[index]);
        First = 0;
    }
    printf("\n");
}

void trans_from_string(my_int *num, char *user_input)
{
    for (int index = MAX - 1, input_index = MAX - 1; index > -1; index--, input_index--)
    {
        if (user_input[input_index] == '\0')
        {
            index++;
        }
        else
        {
            if (input_index < 0)
            {
                (*num)[index] = '0';
            }
            else
            {
                (*num)[index] = user_input[input_index];
            }
        }
    }
}