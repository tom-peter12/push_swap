/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:28:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 16:28:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_print(t_stacks *stacks, char c)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (c == 'a')
	{
		tmp = stacks->stack_a;
		while (i < stacks->size_a)
		{
			ft_printf("|%d| \n", tmp->content);
			tmp = tmp->next;
			i++;
		}
	}
	else if (c == 'b')
	{
		tmp = stacks->stack_b;
		while (i < stacks->size_b)
		{
			ft_printf("|%d| \n", tmp->content);
			tmp = tmp->next;
			i++;
		}
	}
}
