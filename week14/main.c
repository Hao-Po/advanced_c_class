#include "main.h"
#include "queue.h"
#include "space.h"

int main (void)
{
    tQueue *queue;
    int operation;
    tQueueNode *target_node;
    int id, score=0, ret;
    queue = createQueue();

    while (1)
    {
        printf("\nWhich type you are going to operate? \n");
        printf("1. Add a type 1 (small) item\n");
        printf("2. Add a type 2 (big) item\n");
        printf("3. Remove a type 1 item with a specific ID\n");
        printf("4. Remove a type 2 item with a specific ID\n");
        
        printf("Chioce: ");
        scanf("%d", &operation);
        
        if (operation == 1 || operation == 2)
        {
            printf("  Enter an ID: ");
            scanf("%d", &id);

            ret = tqueue_enqueue(queue, id, score, (operation == 1) ? 0 : 1);

            if (ret == 0)
            {
                printf("    Cannot enter to the queue!\n");
            }
            print_buffer_status();
        }
        else if (operation == 3 || operation == 4)
        {
            printf ("  Enter an ID to remove: ");
            scanf("%d", &id);
            target_node = NULL;
            target_node = find_target_node(queue, id, (operation == 3) ? 0 : 1);

            if (target_node == NULL)
            {
                printf ("    Cannot find the target node! \n");
            }
            else{
                tqueue_dequeue(queue, target_node, (operation == 3) ? 0 : 1);
            }
            print_buffer_status();
        }
        else
        {
            printf ("    No such operation! \n");   
        }
        print_queue(queue);
    }
}
