#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    t_push_swap set;
    t_deque	deque1;
	t_deque	deque2;
	
    init_set(&set, &deque1, &deque2);

    // for (int i = 0; i < 10; i++)
    // {
    //     push_top(set.b, i);
    //     printf("size: %d top: %d bottom: %d\n", set.b->size, set.b->top->data, set.b->bottom->data);
    // }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        push_top(set.a, i);
        printf("size: %d top: %d bottom: %d\n", set.a->size, set.a->top->data, set.a->bottom->data);
    }

    for (int i = 0; i < 4; i++)
    {
        pa(&set);
        printf("size: %d top: %d bottom: %d\n", set.a->size, set.a->top->data, set.a->bottom->data);
    }

}