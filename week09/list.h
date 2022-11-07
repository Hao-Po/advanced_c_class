#ifndef LIST_H
#define LIST_H

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

void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void add_number(tNumStorHead *list, int input_number, int location, int before_or_after);
void del_number(tNumStorHead *list, int location);

#endif