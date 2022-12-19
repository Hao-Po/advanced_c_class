#include "main.h"
#include "queue.h"
#include "space.h"

int main (void)
{
    tQueue *queue;
    tQueueNode *target_node;
    int operation, id, score=0, space = NUM_BTYE_BUF, ret, data_type;
    queue = createQueue();

    while (1)
    {
        printf("Remaining memory space %d\n", space);
        printf("Which type you are going to operate? \n");
        printf("1. Add an item\n");
        printf("2. Remove an item with a specific ID\n");
        
        printf("Chioce: ");
        scanf("%d", &operation);
        
        if (operation == 1){
            printf("  Enter an ID: ");
            scanf("%d", &id);

            printf("  Specify data type(units) you want: ");
            scanf("%d", &data_type);

            ret = enqueue_data(queue, id, score, data_type, &space);

            if (ret == 0){
                printf("    Cannot enter to the queue!\n");
            }
            print_buffer_status();
        }
        else if (operation == 2){
            printf ("  Enter an ID to remove: ");
            scanf("%d", &id);
            target_node = NULL;
            target_node = find_target_node(queue, id);

            if (target_node == NULL){
                printf ("    Cannot find the target node! \n");
            }
            else{
                dequeue_data(queue, target_node, &space);
            }
            print_buffer_status();
        }
        else{
            printf ("    No such operation! \n");   
        }
        print_queue(queue);
    }
}
