#include <stdio.h>
#include <stdlib.h>

typedef struct num_list{
    int counts;
    int *p_list;
}tNumList;

void bubble_sort(tNumList *list){
    int temp;

    for(int i = 0; i < list->counts - 1; i++){
        for(int j = i + 1; j < list->counts; j++){
            if(*(list->p_list + i) > *(list->p_list + j)){
                temp = *(list->p_list + i);
                *(list->p_list + i) = *(list->p_list + j);
                *(list->p_list + j) = temp;
            }
        }
    }
}

void merge(tNumList *list1, tNumList *list2){
    int list1_index = 0;
    int list2_index = 0;
    int merge_list_index = 0;
    int *merge_list = (int* ) malloc (sizeof(int) * (list1->counts + list2->counts));

    while((list1_index < list1->counts) && (list2_index < list2->counts)){
        if (*(list1->p_list + list1_index) <= *(list2->p_list + list2_index)){
            *(merge_list + merge_list_index) = *(list1->p_list + list1_index);
            list1_index++;
        }
        else{
            *(merge_list + merge_list_index) = *(list2->p_list + list2_index);
            list2_index++;
        }
        merge_list_index++;
    }

    while(list1_index < list1->counts){
        *(merge_list + merge_list_index) = *(list1->p_list + list1_index);
        list1_index++;
        merge_list_index++;
    }

    while(list2_index < list2->counts){
        *(merge_list + merge_list_index) =*(list2->p_list + list2_index);
        list2_index++;
        merge_list_index++;
    }

    printf("merged list: ");
    for(int index = 0; index < list1->counts + list2->counts; index++){
        printf("%d ", *(merge_list + index));
    }
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

    printf("Please enter how many numbers in list2: ");
    scanf("%d", &(list2.counts));

    list2.p_list = (int*) malloc (sizeof(int) * list2.counts);
    
    printf("    Please input %d numbers: ", list2.counts);
    for(int index = 0; index < list2.counts; index++){
        scanf("%d", list2.p_list + index);
    }
    
    bubble_sort(&list1);
    bubble_sort(&list2);

    printf("sorted list1: ");
    for(int index = 0; index < list1.counts; index++){
        printf("%d ", *(list1.p_list + index));
    }
    printf("\n");
    printf("sorted list2: ");
    for(int index = 0; index < list2.counts; index++){
        printf("%d ", *(list2.p_list + index));
    }
    printf("\n");

    merge(&list1, &list2);
    
    return 0;
}
