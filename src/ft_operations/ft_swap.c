/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:03:55 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 16:03:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap_(t_list **head)
{
	int		temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
}

void	ft_swap(t_stacks *stacks, char c, int n)
{
	if (c == 'a' && stacks->stack_a && stacks->stack_a->next)
	{
		ft_swap_(&stacks->stack_a);
		if (n == 1)
			ft_putstr("sa\n");
	}
	if (c == 'b' && stacks->stack_b && stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_b);
		if (n == 1)
			ft_putstr("sb\n");
	}
	if (c == 's' && stacks->stack_a && stacks->stack_a->next && stacks->stack_b
		&& stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_a);
		ft_swap_(&stacks->stack_b);
		if (n == 1)
			ft_putstr("ss\n");
	}
}
