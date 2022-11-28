#include "space.h"

tTypeScore score_buf[N]; //preallocated memory space

void get_score_space(tTypeScore **pp_score, int score)
{
    int index;
    for (index = 0; index < N; index++){
        if (!score_buf[index].used){
            break;
        }
    }

    printf("     get_score_space(): giving space numbered %d\n\n", index);
    (*pp_score) = &score_buf[index];
    (*pp_score)->score = score;
    (*pp_score)->loc = index;
    (*pp_score)->used = 1;
}

void return_score_space (int loc)
{
    score_buf[loc].used = 0;
    printf("     return_score_space(): return space numbered %d\n\n", loc);
}
