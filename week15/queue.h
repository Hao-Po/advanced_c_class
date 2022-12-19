#ifndef __QUEUE__
#define __QUEUE__

typedef struct queue_node {
    int id;
    int score;
    int location;
    int data_type;
    struct tQueueNode *next;
    struct tQueueNode *prev;    
}tQueueNode;

typedef struct {
    tQueueNode *front;
    tQueueNode *rear;
    int count;
}tQueue;

tQueue *createQueue(void);
int enqueue_data(tQueue *queue, int id, int score, int data_type);
int dequeue_data(tQueue *queue, tQueueNode *target, int data_type);
tQueueNode *find_target_node(tQueue *queue, int id);
void print_queue(tQueue *queue);

#endif