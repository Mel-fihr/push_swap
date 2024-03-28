/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:50:00 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/21 20:28:06 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_content
{
    int number;
    int index;
}   t_content;

typedef struct s_list
{
    t_content   *content;
    struct s_list *next;
}   t_list;

typedef struct s_stack
{
    t_list *a;
    t_list *b;
}   t_stack;

typedef struct s_data
{
	int *tab;
	int size;
	char **arr;
}	t_data;

t_list	*ft_lstnew(void *content);
void parsing(int ac, char **av, t_stack *stack);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);
void error();
void check_input(const char *s);
void min_max(long long n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void reverse_rotate(t_list **stack);
void rotate(t_list **stack);
void push(t_list **src, t_list **dest);
void swap(t_list **stack);
void sa(t_stack *s);
void sb(t_stack *s);
void ss(t_stack *s);
void pa(t_stack *s);
void pb(t_stack *s);
void ra(t_stack *s);
void rb(t_stack *s);
void rr(t_stack *s);
void rra(t_stack *s);
void rrb(t_stack *s);
void rrr(t_stack *s);
int compare_ints(const void *a, const void *b);
int binary_search(int *array, int len, int target);
int	ft_lstsize(t_list *lst);
void sort_three(t_stack *stack);
