#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TOTAL 200

int HEX2DEC(char *buf){
    int dec = 0, value;
    int power_num = strlen(buf) - 2;
    for(int index = 1; index < strlen(buf); index++){
        switch(buf[index]) {
            case '0':
                value = 0;
                break;
            case '1': 
                value = 1;
                break;
            case '2': 
                value = 2;
                break;
            case '3': 
                value = 3;
                break;
            case '4': 
                value = 4;
                break;
            case '5': 
                value = 5;
                break;
            case '6': 
                value = 6;
                break;
            case '7': 
                value = 7;
                break;
            case '8': 
                value = 8;
                break;
            case '9': 
                value = 9;
                break;
            case 'A': case 'a': 
                value = 10;
                break;
            case 'B': case 'b':
                value = 11;
                break;
            case 'C': case 'c':
                value = 12;
                break;
            case 'D': case 'd':
                value = 13;
                break;
            case 'E': case 'e':
                value = 14;
                break;
            case 'F': case 'f':
                value = 15;
                break;
        } 
        dec +=  pow(16, power_num) * value;
        power_num--;
    }

    return dec;
}

int BIN2DEC(char *buf){
    int dec = 0;
    int power_num = strlen(buf) - 2;
    for(int index = 1; index < strlen(buf); index++){
        dec +=  pow(2, power_num) * (buf[index] - 48);
        power_num--;
    }

    return dec;
}

void HEX_BIN_TO_DEC(char *buf, int (*change)(char *)){
    int dec = change(buf);
    printf("    Result: %d \n", dec);
}

int main(void){
    char *buf = (char *) malloc (sizeof(char) * TOTAL);
    void (*func[2]) = {BIN2DEC, HEX2DEC};

    while(1){
        printf("Please specify the input: ");
        scanf("%s", buf);

        if (buf[0] == 'b' || buf[0] == 'B'){
            HEX_BIN_TO_DEC(buf, BIN2DEC);
        }
        else if (buf[0] == 'h' || buf[0] == 'H'){
            HEX_BIN_TO_DEC(buf, HEX2DEC);
        }
    }
}