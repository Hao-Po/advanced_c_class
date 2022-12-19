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

int enqueue_data(tQueue *queue, int id, int score, int data_type, int *space){
    tQueueNode *queue_node = NULL;
    int mem_location;

    our_malloc (data_type, (void *) &queue_node, &mem_location);

    if (queue_node == NULL){
        printf("    Enqueue Failed !!! \n");
        return 0;
    }
    
    queue_node->id = id;
    queue_node->score = score;
    queue_node->location = mem_location;
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
    
    *space = *space - data_type;
    queue->count++;
    return 1;
}

int dequeue_data(tQueue *queue, tQueueNode *target, int *space){
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

    our_free(target->location, target->data_type);
    *space = *space + target->data_type;
    queue->count--;
    return 1;   
}

tQueueNode *find_target_node(tQueue *queue, int id){
    tQueueNode *target = queue->front;

    while(target != NULL){
        if (target->id == id){
            return target;
        }
        target = target->next;
    }

    return NULL;
}

void print_queue (tQueue *queue)
{
    tQueueNode *target = queue->front;

    printf("      queue content: ");    
    for (int i = 0; i < queue->count; i++){
        printf ("%d(%d, %d) ", target->id, target->location, target->data_type);
        target = target->next;
    }
    printf("\n\n");
}