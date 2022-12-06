#include "main.h"
#include "queue.h"
#include "space.h"

int main (void)
{
    tQueue *queue;
    int operation;
    tQueueSmall *target_type_small;
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

            ret = enqueue_type_small(queue, id, score, operation);

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
            target_type_small = NULL;
            target_type_small = find_target_small_node(queue, id, operation);

            if (target_type_small == NULL)
            {
                printf ("    Cannot find the target node! \n");
            }
            else{
                dequeue_type_small(queue, target_type_small, operation);
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
