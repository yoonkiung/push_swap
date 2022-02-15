/*
#include <stdio.h>
#include "header.h"

int main()
{
    t_deque deqa;
    t_deque deqb;
    dequeinit(&deqa);
    dequeinit(&deqb);

    dqaddfirst(&deqa, 3);
    dqaddfirst(&deqa, 2);
    dqaddfirst(&deqa, 1);

    dqaddlast(&deqa, 4);
    dqaddlast(&deqa, 5);
    dqaddlast(&deqa, 6);

    //dqaddfirst(&deqb, 10);
    //dqaddfirst(&deqb, 11);
    //dqaddfirst(&deqb, 12);

    //push(&deqa, &deqb);
    reverse_rotate(&deqa); 
    while (!dequeisempty(&deqa))
        printf("%d ", dqremovefirst(&deqa));
   
}
*/