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
    tNumList *list1, *list2;
    
    printf("Please enter how many numbers in list1: ");
    scanf("%d", &(list1->counts));

    // int *list1_array = (int* )malloc(sizeof(int) * list1->counts);
    // list1->p_list =  list1_array;
    printf("    Please input %d numbers: ", list1->counts);

    for(int i = 0; i < 3; i++){
        printf("!");
    }
 
    
    // printf("Please enter how many numbers in list2: ");
    // scanf("%d", &(list2->counts));
    
    // int *list2_array = (int* )malloc(sizeof(int) * list2->counts);
    // list2->p_list = list2_array;
    // printf("    Please input %d numbers: ", list2->counts);

    return 0;
}
