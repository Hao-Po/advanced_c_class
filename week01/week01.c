#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    int count = 0;

    printf("Please input a character sequence: ");
    scanf("%s", str);

    for(int i = 0; i < strlen(str)-1; i++){
        for(int j = i+1; j < strlen(str); j++){
            if(*(str+i) > *(str+j)){
                count++; 
            }
        }
    }

    printf("  number of inversions: %d", count);

    return 0;
}