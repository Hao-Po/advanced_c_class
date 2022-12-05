#include "stack.h"

tStack *create_stack(void)
{
    tStack *stack;
    stack = (tStack *) malloc (sizeof(tStack));
    stack->count = 0;
    stack->head = NULL;

    return stack;
}

void handle_push_operation(tStack *stack_ptr)
{
    int score;

    if (stack_ptr->count == N){
        printf ("[Error]  handle_push_operation(): space full \n\n");
    }
    else{
        printf("  handle_push_operation(): enter score value: ");
        scanf("%d", &score);
        
        tNode *node;
        node = (tNode *) malloc (sizeof(tNode));

        if (stack_ptr->count == 0){
            stack_ptr->head = node;
            node->next = NULL;
        }
        else{
            node->next = stack_ptr->head;
            stack_ptr->head = node;
        }

        get_score_space(&(node->data_ptr), score);
        stack_ptr->count++;
    }
}

void handle_pop_operation(tStack *stack_ptr)
{
    if (stack_ptr->count == 0){
        printf ("[Error]  handle_pop_operation(): nothing in stack \n\n");
    }
    else{
        printf("  handle_pop_operation(): poped value: %d\n", stack_ptr->head->data_ptr->score);
        return_score_space(stack_ptr->head->data_ptr->loc);
        
        tNode *node_ptr = stack_ptr->head;
        stack_ptr->head = stack_ptr->head->next;
        free(node_ptr);
        stack_ptr->count--;
    }
}

void print_stack_content(tStack *stack_ptr)
{
    tNode *node_ptr = stack_ptr->head;

    printf("   print_stack_content(): stack items -> ");

    while (node_ptr != NULL){
        printf("%d(%d) ", node_ptr->data_ptr->score, node_ptr->data_ptr->loc);
        node_ptr = node_ptr->next;
    }

    printf("\n");
}

