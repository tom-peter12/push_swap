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

#include "../includes/push_swap.h"

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

int	main(int argc, char *argv[])
{
	int			i;
	char		*comb;
	t_stacks	*stack;

	if (argc > 1)
	{
		stack = malloc(sizeof(t_stacks));
		i = 1;
		comb = ft_strdup("");
		while (i < argc)
			comb = ft_strjoin(ft_strjoin(comb, argv[i++]), " ");
		if (ft_check_empty(argc, argv) || ft_check_invalid_args(comb)
			|| ft_check_duplicate(comb))
			ft_put_error(comb, stack);
		ft_create_stack_a(comb, stack);
		ft_magic(stack);
		ft_stack_freer(&(stack->stack_a), stack->size_a);
		free(comb);
		free(stack);
	}
	return (0);
}
