#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    char **ptr = argv+1;
    int num = atoi(*ptr);
    for(int index = 1; index < argc-1; index++){
        printf("%s ", *((ptr)+index));
        if((index) % (int)sqrt(num) == 0){
            printf("\n");
        }
    }


    // printf("%d", num);
    return 0;
}