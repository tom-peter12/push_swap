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

#include "../includes/push_swap.h"

void	ft_rev_rotate_(t_list **first, int stack_size)
{
	int		j;
	t_list	*temp;

	j = 0;
	temp = *first;
	while (j < stack_size - 1)
	{
		temp = temp->next;
		j++;
	}
	(*first) = temp;
}

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a)
	{
		ft_rev_rotate_(&stacks->stack_a, stacks->size_a);
		ft_putstr(GREEN"rra\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_b, stacks->size_b);
		ft_putstr(GREEN"rrb\n"NORMAL);
	}
	if (c == 'r' && stacks->stack_a && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_a, stacks->size_a);
		ft_rev_rotate_(&stacks->stack_b, stacks->size_b);
		ft_putstr(GREEN"rrr\n"NORMAL);
	}
}