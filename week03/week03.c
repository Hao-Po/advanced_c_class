#include <stdio.h>
#include <stdlib.h>

typedef struct num_list{
    int counts;
    int *p_list;
}tNumList;

void bubble_sort(tNumList *list){

}

void merge(tNumList *list1, tNumList *list2){

}

int main(void){
    tNumList *list = (tNumList *) malloc (sizeof(tNumList) * 2);
    // tNumList *list1 = list[0];


    printf("Please enter how many numbers in list1: ");
    scanf("%d", &(list1->counts));
    printf("    Please input %d numbers: ", list1->counts);

    return 0;
}
