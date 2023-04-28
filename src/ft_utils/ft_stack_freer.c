/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_freer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:22:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/24 15:22:06 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_freer(t_list **stack, int size)
{
	t_list	*temp;
	int		i;

	i = 0;
	if (!stack || !(*stack))
		return ;
	while (i < size)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
		i++;
	}
	*stack = NULL;
}
