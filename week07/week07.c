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
            if (list->counts != 0){
                del_number(list);
            }
            else{
                printf("  Nothing can delete.\n");
            }
        }
        else if (input == -1){
            break;
        }
        else{
            printf("  No such choice !\n");
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

    if (list->counts == 0){         // the first insert
        list->head = new_number;
        list->tail = new_number; 
    }
    else{
        printf("  Specify a target location: ");
        scanf("%d", &location);
        
        if (location > list->counts || location < 1){
            printf("  No such choice !\n");
            return;
        }

        node_ptr = list->head;

        for(int i = 0; i < location - 1; i++){  // go to location node
            node_ptr = node_ptr->next;
        }

        printf("  1. Before or 2. After the location %d: ", location);
        scanf("%d", &before_or_after);

        if (before_or_after == 1){                      // choose "before"
            if (node_ptr == list->head){                // if location == head && insert "before" (insert head)
                node_ptr->prev = new_number;            // ex. NULL <-- 3 <--> 5 --> NULL to NULL <-- 1 <--> 3 <--> 5 --> NULL
                new_number->next = node_ptr;
                list->head = new_number;
            }
            else{                                       // other possibilities (insert before node)
                new_number->prev = node_ptr->prev;      // ex. NULL <-- 3 <--> 5 --> NULL to NULL <-- 3 <--> 4 <--> 5 --> NULL
                new_number->next = node_ptr;
                node_ptr->prev->next = new_number;
                node_ptr->prev = new_number;
            } 
        }
        else if (before_or_after == 2){                 // choose "after"
            if (node_ptr == list->tail){                // if location == tail && insert "after" (insert tail)
                node_ptr->next = new_number;            // ex. NULL <-- 3 <--> 5 --> NULL to NULL <-- 3 <--> 5 <--> 7 --> NULL
                new_number->prev = node_ptr;
                list->tail = new_number;
            }
            else{                                       // other possibilities (insert after node)
                new_number->prev = node_ptr;            // ex. NULL <-- 3 <--> 5 --> NULL to NULL <-- 3 <--> 4 <--> 5 --> NULL
                new_number->next = node_ptr->next;
                node_ptr->next->prev = new_number;
                node_ptr->next = new_number;
            }
        }
    }

    list->counts++;
    print_list(list);
}

void del_number(tNumStorHead *list){
    int location;
    tNumStorage *node_ptr;

    printf("  Specify a target location: ");
    scanf("%d", &location);

    if (location > list->counts || location < 1){
        printf("  No such choice !\n");
        return;
    }

    if (list->counts == 1){    // only one node can delete.
        list->head = NULL;
        list->tail = NULL;
    }
    else{
        node_ptr = list->head;

        for(int i = 0; i < location - 1; i++){          // go to location node
            node_ptr = node_ptr->next;
        }

        if (node_ptr == list->head){                    // del head node
            list->head = node_ptr->next;
            list->head->prev = NULL;
        }
        else if (node_ptr == list->tail){               // del tail node
            list->tail = node_ptr->prev;
            list->tail->next = NULL;
        }
        else{                                           // del middle node
            node_ptr->next->prev = node_ptr->prev;
            node_ptr->prev->next = node_ptr->next;
        }
    }

    free(node_ptr);
    list->counts--;
    print_list(list);
}