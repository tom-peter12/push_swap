/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:07:02 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 16:07:04 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rev_rotate_(t_list **first)
{
	t_list	*last;

	last = (*first)->prev;
	(*first) = last;
}

void	ft_rev_rotate(t_stacks *stacks, char c, int n)
{
	if (c == 'a' && stacks->stack_a)
	{
		ft_rev_rotate_(&stacks->stack_a);
		if (n == 1)
			ft_putstr("rra\n");
	}
	if (c == 'b' && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_b);
		if (n == 1)
			ft_putstr("rrb\n");
	}
	if (c == 'r' && stacks->stack_a && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_a);
		ft_rev_rotate_(&stacks->stack_b);
		if (n == 1)
			ft_putstr("rrr\n");
	}
}
