#include "../push_swap.h"

void sa(t_stack *s)
{
    swap(&(s->a));
    write(1, "sa\n", 3);
}