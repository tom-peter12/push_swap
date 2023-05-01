/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:39:52 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/09 12:39:53 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
}

void	ft_create_stack_a(char *str, t_stacks *stack)
{
	char		**holder;
	t_list		*ll_a;
	int			i;
	int			c;

	i = 0;
	c = 0;
	holder = ft_split(str, ' ');
	ft_init_stacks(stack);
	while (holder[i])
	{
		c = ft_atoi(holder[i]);
		ll_a = ft_lstnew(c);
		ft_lstadd_back(&stack->stack_a, ll_a);
		i++;
	}
	stack->size_a = i;
	ft_freer(holder);
}

void	ft_magic(t_stacks *stacks)
{
	if (stacks->size_a == 1 || is_sorted(&stacks->stack_a))
		return ;
	else if ((stacks->size_a) == 2)
		ft_swap(stacks, 'a');
	else if ((stacks->size_a) == 3)
		ft_3_elem(stacks);
	else if ((stacks->size_a) <= 5)
		ft_tiny_sort(stacks);
	else if ((stacks->size_a >= 6))
		ft_big_sort(stacks, stacks->size_a);
}
