#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap_row(int **int_a, int **int_b){
    int *tmp = *int_a;
    *int_a = *int_b;
    *int_b = tmp;
}

void swap_col(int *int_a, int *int_b){
    int tmp = *int_a;
    *int_a = *int_b;
    *int_b = tmp;
}

void print_all(int **row_array, int sqrt_num){
    for(int row = 0; row < sqrt_num; row++){
        for(int col = 0; col < sqrt_num; col++){
            printf("%2d ", *(*(row_array + row) + col));
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    int num = atoi(*(argv+1));
    int sqrt_num = sqrt(num);

    if(sqrt_num < 3 || (sqrt_num * sqrt_num) != num){
        printf("Input 1+x2 numbers (The first number is total number, x>3).");
        return 0;
    }

    int *array = (int *)malloc(sizeof(int) * num); // store all argv's character
    int **rows_array = (int **)malloc(sizeof(int) * sqrt_num); // store all rows

    for(int index = 0; index < num; index++){
        *(array + index) = atoi(*(argv + 2 + index)); // change all char to int
    }

    for(int index = 0; index < sqrt_num; index++){
        *(rows_array + index) = (array + index * sqrt_num); // pointer to pointer,  like 2d vector
    }

    print_all(rows_array, sqrt_num);

    swap_row(rows_array + 0, rows_array + 2); // change row

    print_all(rows_array, sqrt_num);

    for(int row = 0; row < sqrt_num; row++){
        swap_col(*(rows_array + row) + 0, *(rows_array + row) + 2); // change col
    }

    print_all(rows_array, sqrt_num);

    return 0;
}

