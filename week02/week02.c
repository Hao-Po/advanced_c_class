#include <stdio.h>

int main(void){
    char a = 'A';
    int *p;

    p = &a;
    printf("%d", *p);
    return 0;
}