/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:05:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 16:05:57 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate_(t_list **first)
{
	t_list	*second;

	second = (*first)->next;
	(*first) = second;
}

void	ft_rotate(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a)
	{
		ft_rotate_(&stacks->stack_a);
		ft_putstr("ra\n");
	}
	if (c == 'b' && stacks->stack_b)
	{
		ft_rotate_(&stacks->stack_b);
		ft_putstr("rb\n");
	}
	if (c == 'r' && stacks->stack_a && stacks->stack_b)
	{
		ft_rotate_(&stacks->stack_a);
		ft_rotate_(&stacks->stack_b);
		ft_putstr("rr\n");
	}
}
