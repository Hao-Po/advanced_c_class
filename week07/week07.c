#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage{
    int number;
    struct num_storage *next;
    struct num_storage *prev;
}tNumStorage;

typedef struct num_stor_head{
    int counts;
    tNumStorage *head;
    tNumStorage *tail;
}tNumStorHead;

void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void add_number(tNumStorHead *list);
void del_number(tNumStorHead *list);

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
    tNumStorage *node_ptr;

    printf("\n");
    printf("counts: %d \n", list->counts);
    node_ptr = list->head;
    printf(" From head --> ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    node_ptr = list->tail;
    printf("\n From tail --> ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->prev;
    }
    printf("\n\n");
}

void get_input(tNumStorHead *list){
    int input = 0;
    while (input != -1){    // looping scan new number until get -1.
        printf("1. Add a number or 2. Delete a number: ");
        scanf("%d", &input); // get choice

        if (input == 1){
            add_number(list);
        }
        else if (input == 2){
            del_number(list);
        }
    }
}

void add_number(tNumStorHead *list){
    int input_number, location, before_or_after;
    tNumStorage *new_number = (tNumStorage *)malloc(sizeof(tNumStorage));
    tNumStorage *node_ptr;
    
    printf(" Add a number: ");
    scanf("%d", &input_number);

    new_number->number = input_number;
    new_number->prev = NULL;
    new_number->next = NULL;

    if (list->counts == 0){
        list->head = new_number;
        list->tail = new_number; 
    }else{
        printf("  Specify a target location: ");
        scanf("%d", &location);

        node_ptr = list->head;
        for(int i = 0; i < location - 1; i++){
            node_ptr = node_ptr->next;
        }

        printf("  1. Before or 2. After the location %d: ", location);
        scanf("%d", &before_or_after);

        if (before_or_after == 1){
            if (node_ptr == list->head){
                new_number->next = node_ptr;
                list->head = new_number;
            }
            else{
                new_number->prev = node_ptr->prev;
                new_number->next = node_ptr;
            } 
        }
        else if (before_or_after == 2){

        }
    }

    list->counts++;
    print_list(list);
}

void del_number(tNumStorHead *list){

}