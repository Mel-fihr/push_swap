#include "../push_swap.h"

void rra(t_stack *s)
{
    reverse_rotate(&(s->a));
    write(1, "rra\n", 4);
}
