/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:49 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/03 20:13:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "get_next_line/get_next_line.h"

int	ft_arg_check(int ar, char *av[], char *sp)
{
	if (ft_check_empty(ar, av) || ft_check_invalid_args(sp)
		|| ft_check_duplicate(sp))
		return (1);
	else
		return (0);
}

void	ft_freerrr(t_stacks *stack)
{
	ft_stack_freer(&(stack->stack_a), stack->size_a);
	if ((stack->stack_b))
		ft_stack_freer(&(stack->stack_b), stack->size_b);
}
