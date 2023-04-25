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

void	ft_magic(t_stacks *stacks)
{
	if (stacks->size_a == 1 || is_sorted(&stacks->stack_a))
		return ;
	else if ((stacks->size_a) == 2)
		ft_swap(stacks, 'a');
	else if ((stacks->size_a) == 3)
		ft_3_elem(stacks);
	else if ((stacks->size_a) <= 6)
		ft_tiny_sort(stacks);
	else if ((stacks->size_a >= 7))
		ft_big_sort(stacks, stacks->size_a);
}
