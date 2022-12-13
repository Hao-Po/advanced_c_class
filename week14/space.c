#include "space.h"

unsigned char buffer[SMALL_ELEMENT_SIZE*NUM_SMALL_BYTE_BUF + NUM_LARGE_BYTE_BUF*LARGE_ELEMENT_SIZE]; // 32 * 8 + 64 * 8
unsigned char byte_small_buf_mask = 0x0; // 0 0 0 0 0 0 0 0
unsigned char byte_large_buf_mask = 0x0; // 0 0 0 0 0 0 0 0


void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
  
    printf ("      byte_small_buf_mask: ");
    for (i = 0; i < NUM_SMALL_BYTE_BUF; i++){
        printf ("%d ", (byte_small_buf_mask & mask) >> (7 - i));
        mask = mask >> 1;
    }
    printf ("\n");

    mask = 0x80;
    printf("      byte_large_buf_mask: ");
    for (i = 0; i < NUM_LARGE_BYTE_BUF; i++){
        printf ("%d ", (byte_large_buf_mask & mask) >> (7 - i));
        mask = mask >> 1;
    }
    printf ("\n");
}

void our_malloc(int data_type, void **target, int *mem_location)
{
    int location;

    if (byte_small_buf_mask == SMALL_FULL && byte_large_buf_mask == LARGE_FULL){
        return;
    }
    else if (data_type == TYPE_SMALL){
        location = test_single_location(byte_small_buf_mask, 0x01);
        if (location >= 0){
            set_single_bit(&byte_small_buf_mask, location);
            *target = &buffer[SMALL_ELEMENT_SIZE * location];
            *mem_location = location;
        }
        else{
            location = test_single_location(byte_large_buf_mask, 0x01);
            set_single_bit(&byte_large_buf_mask, location);
            *target = &buffer[SMALL_ELEMENT_SIZE * NUM_SMALL_BYTE_BUF + LARGE_ELEMENT_SIZE * location];
            *mem_location = location + 8;
        }
        
    }
    else{ // TYPE_LARGE
        location = test_single_location(byte_large_buf_mask, 0x01);
        if (location >= 0){
            set_single_bit(&byte_large_buf_mask, location);
            *target  = &buffer[SMALL_ELEMENT_SIZE * NUM_SMALL_BYTE_BUF + LARGE_ELEMENT_SIZE * location];
            *mem_location = location + 8;
        }
        else{
            location = test_dual_location(byte_small_buf_mask, 0x03);
            if (location >= 0){
                set_dual_bit(&byte_small_buf_mask, location);
                *target  = &buffer[SMALL_ELEMENT_SIZE * location];
                *mem_location = location;
            }
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

void our_free(int data_type, int mem_location){
    if (data_type == TYPE_SMALL){
        if (mem_location < 8){
            clear_single_bit(&byte_small_buf_mask, mem_location);
        }else{
            clear_single_bit(&byte_large_buf_mask, mem_location - 8);
        }
    }
    else{ // TYPE_LARGE
        if (mem_location < 8){
            clear_dual_bit(&byte_small_buf_mask, mem_location);
        }else{
            clear_single_bit(&byte_large_buf_mask, mem_location - 8);
        }
    }
}
