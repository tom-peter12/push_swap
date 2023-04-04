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

#include "../includes/push_swap.h"

void	ft_print(t_stacks *stacks)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stacks->stack_a;
	while (i < stacks->size_a)
	{
		ft_printf("|%d| \n", tmp->content);
		tmp = tmp->next;
		i++;
	}
}
