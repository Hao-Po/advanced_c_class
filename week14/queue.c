#include "queue.h"
#include "space.h"

tQueue *createQueue(void){    
    tQueue *queue;
    queue = (tQueue *) malloc (sizeof(tQueue));

    if (queue){
        queue->front = NULL;
        queue->rear = NULL;  
        queue->count = 0;
    }

    return queue;
}

int tqueue_enqueue(tQueue *queue, int id, int score, int data_type){
    tQueueNode *queue_node;
    void *newptr = NULL;
    int mem_location;

    queue_node = (tQueueNode *) malloc (sizeof(tQueueNode));
    our_malloc (data_type, (void *) &newptr, &mem_location);

    if (newptr == NULL){
        printf("    Enqueue Failed !!! \n\n");
        return 0;
    }

    if (data_type == TYPE_SMALL){
        ((tQueueSmall *)newptr)->id = id;
        ((tQueueSmall *)newptr)->location = mem_location;
        ((tQueueSmall *)newptr)->score = score;
    } 
    else{
        ((tQueueLarge *)newptr)->id = id;
        ((tQueueLarge *)newptr)->location = mem_location;
        ((tQueueLarge *)newptr)->score[0] = score;
    }
    
    queue_node->content = newptr;
    queue_node->data_type = data_type;
    queue_node->prev = NULL;
    queue_node->next = NULL;

    if (queue->count == 0){
        queue->front = queue_node;
        queue->rear = queue_node;
    }
    else{
        queue->rear->next = queue_node;
        queue_node->prev = queue->rear;
        queue->rear = queue_node;
    }
    
    queue->count++;
    return 1;
}

int tqueue_dequeue(tQueue *queue, tQueueNode *target, int data_type){
    if (data_type == TYPE_SMALL){
        printf("target type: %d, location: %d, id: %d\n", target->data_type, ((tQueueSmall *)target->content)->location, ((tQueueSmall *)target->content)->id);
        if (target->next != NULL){
            printf("target next type: %d, location: %d, id: %d\n", target->next->data_type, ((tQueueSmall *)target->next->content)->location, ((tQueueSmall *)target->next->content)->id);
        }
    }
    else{
        printf("target type: %d, location: %d, id: %d\n", target->data_type, ((tQueueLarge *)target->content)->location, ((tQueueLarge *)target->content)->id);
        if (target->next != NULL){
            printf("target next type: %d, location: %d, id: %d\n", target->next->data_type, ((tQueueLarge *)target->next->content)->location, ((tQueueLarge *)target->next->content)->id);
        }
    }

    if (queue->count == 1){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        if (target == queue->front){
            queue->front = target->next;
            queue->front->prev = NULL;
        }
        else if (target == queue->rear){
            queue->rear = target->prev;
            queue->rear->next = NULL;
        }
        else{
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
    }

    if (data_type == TYPE_SMALL){
        our_free(data_type, ((tQueueSmall *)target->content)->location);
    }
    else{
        our_free(data_type, ((tQueueLarge *)target->content)->location);
    }

    queue->count--;
    return 1;   
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type){
    tQueueNode *target = queue->front;

    while(target != NULL){
        if (data_type == TYPE_SMALL){
            if ((((tQueueSmall *)target->content)->id == id) && (target->data_type == data_type)){
                return target;
            }
        }
        else{
            if ((((tQueueLarge *)target->content)->id == id) && (target->data_type == data_type)){
                return target;
            }
        }
        target = target->next;
    }

    return NULL;
}

void print_queue (tQueue *queue)
{
    tQueueNode *target = queue->front;

    printf("      type mixed queue: ");    
    for (int i = 0; i < queue->count; i++)
    {
        if (target->data_type == TYPE_SMALL){
            printf ("%d(%d,%d) ", ((tQueueSmall *)target->content)->id, target->data_type, ((tQueueSmall *)target->content)->location);
        }
        else{
            printf ("%d(%d,%d) ", ((tQueueLarge *)target->content)->id, target->data_type, ((tQueueLarge *)target->content)->location);
        }
        target = target->next;
    }
    printf("\n");
}