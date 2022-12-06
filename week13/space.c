#include "space.h"

unsigned char buffer[SMALL_ELEMENT_SIZE * NUM_SMALL_BYTE_BUF]; // 32 * 8
unsigned char byte_small_buf_mask = 0x0; // 0 0 0 0 0 0 0 0

void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
  
    printf ("      byte_small_buf_mask: ");
    for (i = 0; i < NUM_SMALL_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_small_buf_mask & mask) >> (7 - i));
        mask = mask >> 1;
    }

    printf ("\n");
}

void our_malloc(int type, void **target, int *mem_location) // type(*target) = tQueueSmall
{
    int location;

    if (byte_small_buf_mask == SMALL_FULL){
        return;
    }
    else if (type == TYPE_SMALL){
        location = test_single_location(byte_small_buf_mask, 0x01);
        if (location >= 0){
            set_single_bit(&byte_small_buf_mask, location);
            *target = &buffer[SMALL_ELEMENT_SIZE * location];
            *mem_location = location;
        }
        else{
            return;
        }
    }
    else{ // TYPE_LARGE
        location = test_dual_location(byte_small_buf_mask, 0x03);
        if (location >= 0){
            set_dual_bit(&byte_small_buf_mask, location);
            *target  = &buffer[SMALL_ELEMENT_SIZE * location];
            *mem_location = location;
        }
        else{
            return;
        }
    }    
}

int test_single_location(int mask, int mask_length){
    for (int location = 0; location < NUM_SMALL_BYTE_BUF; location++){
        if (!(mask & mask_length)){
            return location;
        }
        mask_length = mask_length << 1;
    }
    return -1;
}

void set_single_bit(unsigned char *mask, int location){
    *mask = *mask | (0x01 << location);
}

int test_dual_location(int mask, int mask_length){
    for (int location = 0; location < NUM_SMALL_BYTE_BUF - 1; location++){
        if (!(mask & mask_length)){
            return location;
        }
        mask_length = mask_length << 1;
    }
    return -1;
}

void set_dual_bit(unsigned char *mask, int location){
    *mask = *mask | (0x03 << location);
}

void clear_single_bit(unsigned char *mask, int location){
    *mask = *mask ^ (0x01 << location);
}

void clear_dual_bit(unsigned char *mask, int location){
    *mask = *mask ^ (0x03 << location);
}

void our_free(int type, int mem_location){
    if (type == TYPE_SMALL){
        clear_single_bit(&byte_small_buf_mask, mem_location);
    }
    else if (type == TYPE_LARGE){
        clear_dual_bit(&byte_small_buf_mask, mem_location);
    }
}
