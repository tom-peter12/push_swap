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

#include "../includes/push_swap.h"

void	ft_swap_(t_list **head)
{
	int		temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
}

void	ft_swap(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a && stacks->stack_a->next)
	{
		ft_swap_(&stacks->stack_a);
		ft_putstr(BLUE"sa\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_b && stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_b);
		ft_putstr(BLUE"sb\n"NORMAL);
	}
	if (c == 's' && stacks->stack_a && stacks->stack_a->next && stacks->stack_b
		&& stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_a);
		ft_swap_(&stacks->stack_b);
		ft_putstr(BLUE"ss\n"NORMAL);
	}
}
