#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void get_input(tNumStorHead *list){
    int  add_or_del = 0;
    while (add_or_del != -1){    // looping scan new number until get -1.
        printf("1. Add a number or 2. Delete a number: ");
        scanf("%d", &add_or_del); // get choice

        if (add_or_del == 1){
            process_add(list);
        }
        else if (add_or_del == 2){
            process_delete(list);
        }
        else if (add_or_del == -1){
            break;
        }
        else{
            printf("  No such choice !\n");
        }
    }
}

void process_add(tNumStorHead *list){
    int input_number, location, before_or_after;

    printf(" Add a number: ");
    scanf("%d", &input_number);
    
    if (list->counts == 0){
        location = 1;
        add_number(list, input_number, location, before_or_after);
        print_list(list);
    }else{
        printf("  Specify a target location: ");
        scanf("%d", &location);
        if (location > list->counts || location < 1){
            printf("  No such choice !\n");
        }else{
            printf("  1. Before or 2. After the location %d: ", location);
            scanf("%d", &before_or_after);
            add_number(list, input_number, location, before_or_after);
            print_list(list);
        }
    }
}

void process_delete(tNumStorHead *list){
    int location;

    if (list->counts != 0){
        printf("  Specify a target location: ");
        scanf("%d", &location);

        if (location > list->counts || location < 1){
            printf("  No such choice !\n");
        }
        else{
            del_number(list, location);
            print_list(list);
        }
    }
    else{
        printf("  Nothing can delete.\n");
    }
}