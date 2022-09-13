#include <stdio.h>
#include <string.h>

int inversionCounter(char str[]);

int main(void){
    char str[100];

    printf("Please input a character sequence: ");
    scanf("%s", str);

    int count = inversionCounter(str);

    printf("  number of inversions: %d", count);

    return 0;
}

int inversionCounter(char str[]){
    int count = 0;

    for(int i = 0; i < strlen(str)-1; i++){
        for(int j = i+1; j < strlen(str); j++){
            if(*(str+i) > *(str+j)){
                count++; 
            }
        }
    }

    return count;
}