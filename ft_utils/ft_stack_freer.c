/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_freer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:22:05 by tomas             #+#    #+#             */
/*   Updated: 2023/03/24 15:22:06 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
