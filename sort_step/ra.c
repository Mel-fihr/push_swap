#include "../push_swap.h"

void ra(t_stack *s)
{
    rotate(&(s->a));
    write(1, "ra\n", 3);
}