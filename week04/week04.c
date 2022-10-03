#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage{
    int number;
    struct num_storage *next;
}tNumStorage;

typedef struct num_stor_head{
    int counts;
    tNumStorage *head;
    tNumStorage *tail;
}tNumStorHead;

void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);

int main (void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr = list->head;

    printf("  list->counts: %d\n", list->counts);
    printf("  The sorted list: ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}

void get_input(tNumStorHead *list){
    int input = 0;
    while (input != -1){
        printf("Input a number: ");
        scanf("%d", &input);

        if(input != -1){
            sort_list(list, input);
            print_list(list);
        }
    }
}

void sort_list(tNumStorHead *list, int input){
    tNumStorage *new_number = (tNumStorage *)malloc(sizeof(tNumStorage));
    
    new_number->number = input;
    new_number->next = NULL;

    if (list->head == 0){
        list->head = new_number;
        list->tail = new_number; 
        list->counts++;
    }
    else{
        tNumStorage *node_ptr = list->head;
        
        while(node_ptr != NULL){
            if (node_ptr->number <= new_number->number){
                node_ptr = node_ptr->next;
            }
            else{

            }
            
        }

        list->tail->next = new_number;
    }

}