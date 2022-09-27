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
            if(*(list->p_list + i) > *(list->p_list + j)){  // compare 2 nums, if left num > right num, swap
                temp = *(list->p_list + i);  // swap
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
    int *merge_list = (int* ) malloc (sizeof(int) * (list1->counts + list2->counts)); // create a new int array to store merge_list

    while((list1_index < list1->counts) && (list2_index < list2->counts)){  // choose the smaller num to put in list
        if (*(list1->p_list + list1_index) <= *(list2->p_list + list2_index)){ // if list1's num is smaller, put list1's num
            *(merge_list + merge_list_index) = *(list1->p_list + list1_index);
            list1_index++;
        }
        else{   // if list2's num is smaller, put list2's num
            *(merge_list + merge_list_index) = *(list2->p_list + list2_index);
            list2_index++;
        }
        merge_list_index++;
    }

    while(list1_index < list1->counts){ // if list2 is empty now, put list1's nums directly
        *(merge_list + merge_list_index) = *(list1->p_list + list1_index);
        list1_index++;
        merge_list_index++;
    }

    while(list2_index < list2->counts){ // if list1 is empty now, put list2's nums directly
        *(merge_list + merge_list_index) =*(list2->p_list + list2_index);
        list2_index++;
        merge_list_index++;
    }

    printf("merged list: "); // print merged list
    for(int index = 0; index < list1->counts + list2->counts; index++){
        printf("%d ", *(merge_list + index));
    }
}

int main(void){
    tNumList list1, list2;
    
    printf("Please enter how many numbers in list1: ");
    scanf("%d", &(list1.counts));

    list1.p_list = (int*) malloc (sizeof(int) * list1.counts);  // create a int array to store list1's num

    printf("    Please input %d numbers: ", list1.counts);
    for(int index = 0; index < list1.counts; index++){  // store list1's num
        scanf("%d", list1.p_list + index);
    }

    printf("Please enter how many numbers in list2: "); 
    scanf("%d", &(list2.counts));

    list2.p_list = (int*) malloc (sizeof(int) * list2.counts); // create a int array to store list2's num
    
    printf("    Please input %d numbers: ", list2.counts);
    for(int index = 0; index < list2.counts; index++){  // store list2's num
        scanf("%d", list2.p_list + index);
    }
    
    bubble_sort(&list1);    // bubbleSort list1
    bubble_sort(&list2);    // bubbleSort list2

    printf("sorted list1: ");   // print sorted list1
    for(int index = 0; index < list1.counts; index++){
        printf("%d ", *(list1.p_list + index));
    }
    printf("\n");
    printf("sorted list2: ");   // print sorted list2
    for(int index = 0; index < list2.counts; index++){
        printf("%d ", *(list2.p_list + index));
    }
    printf("\n");

    merge(&list1, &list2);  // merge 2 lists into 1 list
    
    return 0;
}