/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:41:16 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/05 14:41:17 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push_(t_list **to, t_list **from)
{
	t_list	*tmp_from;

	tmp_from = NULL;
	if ((*from) != (*from)->next)
	{
		tmp_from = (*from)->next;
		tmp_from->prev = (*from)->prev;
		(*from)->prev->next = tmp_from;
	}
	if (!(*to))
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = tmp_from;
}

void	ft_push(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_b)
	{
		ft_push_(&stacks->stack_a, &stacks->stack_b);
		stacks->size_a++;
		stacks->size_b--;
		ft_putstr("pa\n");
	}
	if (c == 'b' && stacks->stack_a)
	{
		ft_push_(&stacks->stack_b, &stacks->stack_a);
		stacks->size_a--;
		stacks->size_b++;
		ft_putstr("pb\n");
	}
}
