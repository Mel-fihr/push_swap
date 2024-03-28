#include "../push_swap.h"

void sort_three(t_stack *stacks)
{
    int first = stacks->a->content->number;
    int second = stacks->a->next->content->number;
    int third = stacks->a->next->next->content->number;

    printf("%d %d %d\n", first, second, third);
    
}
