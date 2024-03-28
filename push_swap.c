/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:47:21 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/24 00:11:19 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

int binary_search(int *array, int len, int target)
{
    int low = 0, high = len - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(array[mid] == target)
            return mid;
        else if(array[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void index_stack_a(t_stack *stack)
{
    int len = ft_lstsize(stack->a);
    int *sorted = malloc(len * sizeof(int));
    t_list *temp = stack->a;
    int i = 0;

    while(temp != NULL)
    {
        sorted[i] = ((t_content*)temp->content)->number;
        temp = temp->next;
        i++;
    }
    qsort(sorted, len, sizeof(int), compare_ints);
    temp = stack->a;
    while(temp != NULL)
    {
        ((t_content*)temp->content)->index = binary_search(sorted, len, ((t_content*)temp->content)->number);
        temp = temp->next;
    }

    free(sorted);
}

int count_stack_a(t_stack *stack) {
    t_list *temp = stack->a;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void print_stack_a(t_stack *stack)
{
    t_list *temp = stack->a;

    while(temp != NULL) {
        t_content *p = temp->content;
        printf("Number: %d, Index: %d\n", p->number, p->index);
        temp = temp->next;
    }
}

int main(int ac, char **av)
{
    int size_a;
    t_stack stack = {NULL, NULL};

    if (ac < 2)
        return (0);
    parsing(ac, av, &stack);
    index_stack_a(&stack);
    size_a = count_stack_a(&stack);
    print_stack_a(&stack);
    sort_three(&stack);
    printf("---------------\n");
    print_stack_a(&stack);
    printf("[%d]\n", size_a);

    return 0;
}