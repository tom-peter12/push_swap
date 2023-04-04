/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:55:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/17 11:55:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *head)
{
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_3_elem(t_stacks *stacks)
{
	int		min;
	int		max;
	t_list	*temp;

	temp = stacks->stack_a;
	min = ft_lstmin(&stacks->stack_a);
	max = ft_lstmax(&stacks->stack_a);
	while (is_sorted(stacks->stack_a))
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

void	ft_magic(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	if ((stacks->size_a) == 2)
		ft_swap(stacks, 'a');
	else if ((stacks->size_a) == 3)
		ft_3_elem(stacks);
	// else if ((stacks->size_a) < 7)
		// ft_tiny_sort(stacks);
	// else if ((stacks->size_a >= 7))
		// ft_big_sort(stacks);
}
