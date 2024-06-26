/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:35:21 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/21 20:19:03 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*l;

	i = 0;
	l = lst;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}
