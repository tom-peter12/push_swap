/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: tpetros <tpetros@student.42abudhabi.ae>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:42 by tomas             #+#    #+#             */
/*   Updated: 2023/03/22 20:13:50 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*temp;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		temp = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->content == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->content > value && temp->index == 0)
			{
				value = temp->content;
				highest = temp;
				temp = stack_a;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

t_list	*ft_create_stack_a(char *str)
{
	char	**holder;
	t_list	*queue_a;
	t_list	*ll_a;
	int		i;
	int		c;

	i = 0;
	c = 0;
	holder = ft_split(str, ' ');
	queue_a = NULL;
	while (holder[i])
	{
		c = ft_atoi(holder[i]);
		ll_a = ft_lstnew(c);
		ft_lstadd_back(&queue_a, ll_a);
		i++;
	}
    assign_index(queue_a, ft_lstsize(queue_a));
    while (queue_a)
    {
        ft_printf("|%d|\n", queue_a->index);
        queue_a = queue_a->next;
    }
	ft_freer(holder);
	return (queue_a);
}
