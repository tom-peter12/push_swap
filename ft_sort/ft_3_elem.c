/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:44:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/05 13:44:24 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_3_elem(t_stacks *stacks)
{
	int		min;
	int		max;
	t_list	*temp;

	temp = stacks->stack_a;
	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	max = ft_lstmax(&stacks->stack_a, stacks->size_a);
	while (!is_sorted(&stacks->stack_a))
	{
		if (temp->content == max)
		{
			ft_rotate(stacks, 'a');
			temp = stacks->stack_a;
		}
		if (temp->content < temp->next->content && temp->next->content == max)
		{
			ft_rev_rotate(stacks, 'a');
			temp = stacks->stack_a;
		}
		if (temp->content > temp->next->content && temp->next->content == min)
		{
			ft_swap(stacks, 'a');
			temp = stacks->stack_a;
		}
	}
}
