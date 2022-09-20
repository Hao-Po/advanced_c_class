#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    int num = atoi(*(argv+1));
    int sqrt_num = sqrt(num);

    char **array = (char **)malloc(sizeof(void *) * sqrt_num);
    // char *row_array = (char *)malloc(sizeof(char) * sqrt_num);
    char row_array[3] = {1,2,3};
    for(int index = 0; index < sqrt_num; index++){
        *(array+index) = row_array;
    }


    for(int index = 0; index < sqrt_num; index++){
        printf("%d", **(array+index));
    }


    printf("%d\n", num);
    printf("%d\n", sqrt_num);
    return 0;
}