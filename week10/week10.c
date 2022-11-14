#include <stdio.h>

typedef unsigned int Int32;
Int32 input;
Int32 high;
Int32 low;

int CheckRangeLoop(Int32 input, Int32 high, Int32 low);
int CheckRangeNoLoop(Int32 input, Int32 high, Int32 low);

int main(void){
    int loop_result, no_loop_result, keep_try = 1;
    while (keep_try == 1){
        printf("Please specify the input: ");
        scanf("%x", &input);

        printf("    Please specify the high: ");
        scanf("%d", &high);
        printf("    Please specify the low: ");
        scanf("%d", &low);

        loop_result = CheckRangeLoop(input, high, low);
        no_loop_result = CheckRangeNoLoop(input, high, low);

        printf("CheckRangeLoop result: %d\n", loop_result);
        printf("CheckRangeNoLoop result: %d", no_loop_result);

        printf("\n\nEnter 1 to keep trying the next round: ");
        scanf("%d", &keep_try);
    }
}

int CheckRangeLoop(Int32 input, Int32 high, Int32 low){
    Int32 left_shift = 0xffffffff, right_shift = 0xffffffff; 
    for (int i = 0; i < 31 - high; i++){
        left_shift = left_shift >> 1;
    }
    for (int i = 0; i < low; i++){
        right_shift = right_shift >> 1;
    }

    return ((left_shift & right_shift & input) > 0) ? 1 : 0;
}

int CheckRangeNoLoop(Int32 input, Int32 high, Int32 low){
    return (((0xffffffff << low) & (0xffffffff >> (31 - high)) & input) > 0) ? 1 : 0;  // remove the bit which is big than high/small than low, give 0
}                                                                                      // do "AND" with 0xffffffff, when the value > 0, it means there
                                                                                       // is 1 inside.