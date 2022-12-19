#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define NUM_BTYE_BUF        23
#define UNIT_ELEMENT_SIZE   32

void print_buffer_status(void);
void our_malloc(int data_type, void **target, int *mem_location);
void our_free(int location, int data_type);
int test_location(int mask_length);
void set_data(int location, int mask_length);
void clear_data(int location, int mask_length);

#endif