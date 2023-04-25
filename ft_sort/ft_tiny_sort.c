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

void	ft_tiny_sort(t_stacks *stacks)
{
	int	min;
	int	max;

	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	max = ft_lstmax(&stacks->stack_a, stacks->size_a);
	while (stacks->size_a != 3)
	{
		if (stacks->stack_a->content == max || stacks->stack_a->content == min)
			ft_rotate(stacks, 'a');
		else
			ft_push(stacks, 'b');
	}
	ft_3_elem(stacks);
	ft_rev_rotate(stacks, 'a');
	if (stacks->stack_b->content < stacks->stack_b->next->content)
		ft_swap(stacks, 'b');
	while (stacks->stack_b)
	{
		while ((stacks->stack_b->content > stacks->stack_a->content)
			|| stacks->stack_a->prev->content > stacks->stack_b->content)
			ft_rev_rotate(stacks, 'a');
		ft_push(stacks, 'a');
	}
	while (is_sorted(&stacks->stack_a))
		ft_rotate(stacks, 'a');
}
