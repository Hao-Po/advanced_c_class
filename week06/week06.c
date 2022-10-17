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

void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void delete_last(tNumStorHead *list);

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
    while (input != -1){    // looping scan new number until get -1.
        printf("Input a number (-1 to exit, -2 to delete last): ");
        scanf("%d", &input);

        if (input == -2){
            delete_last(list);
        }
        else if (input != -1){
            sort_list(list, input);
        }
    }
}

void sort_list(tNumStorHead *list, int input){
    tNumStorage *new_number = (tNumStorage *)malloc(sizeof(tNumStorage));
    tNumStorage *node_ptr;

    new_number->number = input;
    new_number->next = NULL;
    new_number->prev = NULL;

    if(list->counts == 0){ // if no number now, the head/tail of list is new number.
        list->head = new_number;
        list->tail = new_number; 
    }
    else if(list->head->number > new_number->number){ // if the first number is bigger than new number, 
        list->head->prev = new_number;                // the new number links the original first number,
        new_number->next = list->head;                // and becomes new first number.
        list->head = new_number;                      
    }
    else{
        node_ptr = list->head;
        
        while(1){                                   // looping
            if(node_ptr->next == NULL){             // if all numbers are not bigger than new number, 
                node_ptr->next = new_number;        // the new number becomes the tail of list.
                new_number->prev = node_ptr;        
                list->tail = new_number; 
                break;                
            }
            else if(node_ptr->next->number > new_number->number){   // if there is a number bigger than new number,
                node_ptr->next->prev = new_number;                  // the new number links will link the the bigger number(insert).
                new_number->next = node_ptr->next;                  // ex. 1 <--> 4  becomes 1 <--> 3 <--> 4.
                node_ptr->next = new_number;                        
                new_number->prev = node_ptr;
                break;
            }
            node_ptr = node_ptr->next;
        }       
    }
    list->counts++;
    print_list(list);
}

void delete_last(tNumStorHead *list){
    if (list->counts == 0){                             // if list->counts = 0, do nothing.
        printf("    There is nothing to delete. \n\n");
        return ;
    }
    else if (list->counts != 1){                        // if list->counts != 1, list->tail go to last 2 number
        list->tail = list->tail->prev;                  // then free the last number
        free(list->tail->next);                         // list->tail->next become NULL again
        list->tail->next = NULL;
        list->counts--;
    }
    else{
        free(list->tail);                               // if list->counts = 1, it means it dont have prev number
        list->tail = NULL;                              // so just free the number, and initial the head and tail.
        list->head = NULL;
        list->counts--;
    }
    print_list(list);
}