#include "space.h"

unsigned char buffer[UNIT_ELEMENT_SIZE * NUM_BTYE_BUF];
unsigned char buffer_mask[NUM_BTYE_BUF] = {0};

void print_buffer_status (void){
    printf ("      buffer_mask: ");
    for (int index = NUM_BTYE_BUF - 1; index > -1; index--){
        printf ("%d ", buffer_mask[index]);
        if (index % 8 == 0){
            printf(", ");
        }
    }
    printf ("\n");
}

void our_malloc(int data_type, void **target, int *mem_location)
{
    int location, is_full = 1;

    for (int index = 0; index < NUM_BTYE_BUF; index++){
        if (buffer_mask[index] == 0){
            is_full = 0;
            break;
        }
    } 
    if (is_full){
        return;
    }
    
    location = test_location(data_type);
    if (location >= 0){
        set_data(location, data_type);
        *target = &buffer[UNIT_ELEMENT_SIZE * location];
        *mem_location = location;
    }
}

int test_location(int mask_length){ // bug is here
    int count = 0, start = -1;
    for (int location = 0; location < NUM_BTYE_BUF; location++){
        if (buffer_mask[location] == 0 && start == -1){
            start = location;
            count++;
        }
        else if (buffer_mask[location] == 0){
            count++;
        }
        else{
            start = -1;
            count = 0;
        }

        if (count == mask_length){
            return start;
        }
    }
    return -1;
}

void set_data(int location, int mask_length){
    for (int count = 0; count < mask_length; count++){
        buffer_mask[location++] = 1;
    }
}

void clear_data(int location, int mask_length){
    for (int count = 0; count < mask_length; count++){
        buffer_mask[location++] = 0;
    }
}

void our_free(int location, int data_type){
    clear_data(location, data_type);
}
