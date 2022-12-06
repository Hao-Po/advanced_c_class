#include "queue.h"
#include "space.h"

tQueue *createQueue(void){    
    tQueue *queue;
    queue = (tQueue *) malloc (sizeof(tQueue));

    if (queue)
    {
        queue->type_small_front = NULL;
        queue->type_small_rear = NULL;  
        queue->type_small_count = 0;
    }

    return queue;
}

int enqueue_type_small(tQueue *queue, int id, int score, int data_type)
{
    tQueueSmall *newptr = NULL; 
    int mem_location;

    if (data_type - 1 == TYPE_SMALL){
        our_malloc(TYPE_SMALL, &newptr, &mem_location);
    }
    else{
        our_malloc(TYPE_LARGE, &newptr, &mem_location);
    }

    if (newptr == NULL){
        printf("    Enqueue False!!! \n");
        return 0;
    }

    newptr->id = id;
    newptr->score = score;
    newptr->location = mem_location;
    newptr->data_type = (data_type - 1); // choice = 1/2, so data_type - 1 = TYPE_SMALL/TYPE_LARGE
    newptr->prev = NULL;
    newptr->next = NULL;

    if (queue->type_small_count == 0){
        queue->type_small_front = newptr;
        queue->type_small_rear = newptr;
    }
    else{
        queue->type_small_rear->next = newptr;
        newptr->prev = queue->type_small_rear;
        queue->type_small_rear = newptr;
    }
    
    queue->type_small_count++;
    return 1;
}

int dequeue_type_small(tQueue *queue, tQueueSmall *target, int data_type)
{   
    if (data_type - 3 == TYPE_SMALL){
        data_type = TYPE_SMALL;
    }
    else{
        data_type = TYPE_LARGE;
    }

    if (queue->type_small_count == 1){
        queue->type_small_front = NULL;
        queue->type_small_rear = NULL;
    }
    else{
        if (target == queue->type_small_front){
            queue->type_small_front = target->next;
            queue->type_small_front->prev = NULL;
        }
        else if (target == queue->type_small_rear){
            queue->type_small_rear = target->prev;
            queue->type_small_rear->next = NULL;
        }
        else{
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
    }

    our_free(data_type, target->location);
    queue->type_small_count--;

    return 1;    
}

tQueueSmall *find_target_small_node(tQueue *queue, int id, int data_type)
{
    tQueueSmall *target = queue->type_small_front;

    while(target != NULL){
        if ((target->id == id) && (target->data_type == (data_type - 3))){ // choice = 3/4, so data_type - 3 = TYPE_SMALL/TYPE_LARGE
            return target;
        }
        target = target->next;
    }

    return NULL;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueSmall *target = queue->type_small_front;

    printf("      type small queue: ");    
    for (i = 0; i < queue->type_small_count; i++)
    {
        printf ("%d(%d) ", target->id, target->data_type);
        target = target->next;
    }
    printf("\n");
}