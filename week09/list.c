#include "list.h"
#include <stdio.h>
#include <stdlib.h>

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

void add_number(tNumStorHead *list, int input_number, int location, int before_or_after){
    tNumStorage *new_number = (tNumStorage *)malloc(sizeof(tNumStorage));
    tNumStorage *node_ptr;
    
    new_number->number = input_number;
    new_number->prev = NULL;
    new_number->next = NULL;

    if (list->counts == 0){         // the first insert
        list->head = new_number;
        list->tail = new_number; 
    }
    else{
        node_ptr = list->head;

        for(int i = 0; i < location - 1; i++){  // go to location node
            node_ptr = node_ptr->next;
        }

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
}

void del_number(tNumStorHead *list, int location){
    tNumStorage *node_ptr;

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
}