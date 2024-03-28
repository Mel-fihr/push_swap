#include "push_swap.h"
#include <ctype.h>
#include <string.h>

void error()
{
	printf("Error\n");
	exit(1);
}

int is_duplicate(char **arr, int size, int res)
{
	int  i;
	int cmp;

	i = 0;
	while (i < size)
	{
		cmp = ft_atoi(arr[i]);
		if (res - cmp == 0)
			return 1;
		i++;
	}
	return 0;
}
void get_valid(t_data *data, char *str)
{
	int i;
	int j;
	int res;
	char **arr;

	i = 0;
	arr = ft_split(str, ' ');
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-' || arr[i][j] == '+')
			j++;
		res = ft_atoi(arr[i]);
		if (is_duplicate(arr, i, res) == 1)
			error();
		i++;
	}
	data->arr = arr;
	data->size = i;
}

void check_av_empty(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == NULL || av[i][0] == '\0' || strcmp(av[i], " ") == 0)
		{
			error();
		}
		i++;
	}
}

static void append_argument(char **all_args, char *arg)
{
	char *temp;

	temp = ft_strjoin(*all_args, " ");
	if (!temp)
		error();
	free(*all_args);
	*all_args = ft_strjoin(temp, arg);
	free(temp);
	if (!*all_args)
		error();
}

static void fill_stack(t_stack *stack, t_data *data)
{
    int i;
    t_list *new_node;

    i = 0;
    while (data->arr[i])
    {
        t_content *new_content = (t_content *)malloc(sizeof(t_content));
        if (!new_content)
            error();
        new_content->number = ft_atoi(data->arr[i]);
        new_content->index = i;
        new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
            error();
        new_node->content = new_content;
        ft_lstadd_back(&stack->a, new_node);

        i++;
    }
}

void parsing(int ac, char **av, t_stack *stack)
{
	t_data  data;
	char    *all_args;
	int     i;

	check_av_empty(av);
	all_args = ft_strdup("");
	if (!all_args)
		error();
	i = 1;
	while (i < ac)
	{
		append_argument(&all_args, av[i]);
		i++;
	}
	get_valid(&data, all_args);
	fill_stack(stack, &data);
	free(all_args);
}

