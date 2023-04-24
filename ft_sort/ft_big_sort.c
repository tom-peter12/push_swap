/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:55:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/07 10:55:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_to_b(t_stacks *s, int min, int mid, int max)
{
	while (s->size_a > 2)
	{
		if (s->stack_a->content <= mid && s->stack_a->content != min &&
			s->stack_a->content != max)
		{
			ft_push(s, 'b');
			ft_rotate(s, 'b');
		}
		else if (s->stack_a->content > mid && s->stack_a->content != min &&
			s->stack_a->content != max)
			ft_push(s, 'b');
		else
			ft_rotate(s, 'a');
	}
	if (s->stack_a->content == min)
		ft_rotate(s, 'a');
}

void	ft_big_sort(t_stacks *stacks, int size)
{
	int	min;
	int	max;
	int	mid;
	int	*temp;

	temp = ft_create_array(stacks, size);
	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	max = ft_lstmax(&stacks->stack_a, stacks->size_a);
	mid = temp[(size - 1) / 2];
	ft_push_to_b(stacks, min, mid, max);
	free(temp);
}
