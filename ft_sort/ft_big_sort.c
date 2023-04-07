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
	ft_putnbr(min);
	ft_putnbr(mid);
	ft_putnbr(max);
}
