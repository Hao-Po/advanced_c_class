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
    while (input != -1){    // looping scan new number until get -1.
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
    tNumStorage *node_ptr;

    new_number->number = input;
    new_number->next = NULL;

    if(list->counts == 0){ // if no number now, the head/tail of list is new number.
        list->head = new_number;
        list->tail = new_number; 
    }
    else if(list->head->number > new_number->number){ // if the first number is bigger than new number, 
        new_number->next = list->head;                // the new number links the original first number,
        list->head = new_number;                      // and becomes new first number.
    }
    else{
        node_ptr = list->head;
        
        while(1){                                   // looping
            if(node_ptr->next == NULL){             // if all numbers are not bigger than new number, 
                node_ptr->next = new_number;       // the new number becomes the tail of list.
                list->tail->next = new_number;
                list->tail = new_number; 
                break;                
            }
            else if(node_ptr->next->number > new_number->number){   // if there is a number bigger than new number,
                new_number->next = node_ptr->next;                  // the new number links will link the the bigger number(insert).
                node_ptr->next = new_number;                        // ex. 1 -> 4  becomes 1 -> 3 -> 4.
                break;
            }
            node_ptr = node_ptr->next;
        }       
    }
    list->counts++;
}