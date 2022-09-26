#include <stdio.h>
#include <stdlib.h>

typedef struct num_list{
    int counts;
    int *p_list;
}tNumList;

void bubble_sort(tNumList *list){
    int temp;

    for(int i = 0; i < list->counts - 1; i++){
        for(int j = i+1; j < list->counts; j++){
            if(*(list->p_list+i) > *(list->p_list+j)){
                temp = *(list->p_list+i);
                *(list->p_list+i) = *(list->p_list+j);
                *(list->p_list+j) = temp;
            }
        }
    }
}

void merge(tNumList *list1, tNumList *list2){

}

int main(void){
    tNumList list1, list2;
    
    printf("Please enter how many numbers in list1: ");
    scanf("%d", &(list1.counts));

    list1.p_list = (int*) malloc (sizeof(int) * list1.counts);

    printf("    Please input %d numbers: ", list1.counts);
    for(int index = 0; index < list1.counts; index++){
        scanf("%d", list1.p_list + index);
    }

    // printf("Please enter how many numbers in list2: ");
    // scanf("%d", &(list2.counts));

    // list2.p_list = (int*) malloc (sizeof(int) * list2.counts);
    
    // printf("    Please input %d numbers: ", list2.counts);
    // for(int index = 0; index < list2.counts; index++){
    //     scanf("%d", list2.p_list + index);
    // }

    
    bubble_sort(&list1);
    printf("sorted list1: ");
    for(int index = 0; index < list1.counts; index++){
        printf("%d", *(list1.p_list + index));
    }


    
    

    return 0;
}
