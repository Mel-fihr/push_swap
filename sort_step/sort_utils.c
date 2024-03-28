#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

void swap(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_content *temp = (*stack)->content;
        (*stack)->content = (*stack)->next->content;
        (*stack)->next->content = temp;
    }
}

void push(t_list **src, t_list **dest)
{
    if (*src)
    {
        t_list *temp = *src;
        *src = (*src)->next;
        temp->next = *dest;
        *dest = temp;
    }
}

void rotate(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *first = *stack;
        *stack = (*stack)->next;
        t_list *temp = *stack;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = first;
        first->next = NULL;
    }
}

void reverse_rotate(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *second_last = NULL;
        t_list *temp = *stack;

        while (temp->next)
        {
            second_last = temp;
            temp = temp->next;
        }

        temp->next = *stack;
        second_last->next = NULL;
        *stack = temp;
    }
}
