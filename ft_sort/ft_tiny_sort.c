/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:41:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/05 14:41:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_four(t_stacks *stacks)
{
	int		min;
	t_list	*tmp;
	
	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	tmp = stacks->stack_a;
	while (stacks->size_a > 3)
	{
		if (tmp->content == min)
			ft_push(stacks, 'b');
		else
			ft_rotate(stacks, 'a');
		tmp = tmp->next;
	}
	ft_3_elem(stacks);
	ft_push(stacks, 'a');
}

void	ft_tiny_sort(t_stacks *stacks)
{
	int		min;
	t_list	*tmp;

	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	tmp = stacks->stack_a;
	while (stacks->size_a > 4)
	{
		if (tmp->content == min)
			ft_push(stacks, 'b');
		else if (tmp->prev->content == min)
		{
			ft_rev_rotate(stacks, 'a');
			ft_push(stacks, 'b');
		}
		else
			ft_rotate(stacks, 'a');
		tmp = tmp->next;
	}
	ft_sort_four(stacks);
	ft_push(stacks, 'a');
}
