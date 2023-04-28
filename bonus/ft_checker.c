/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:41:12 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/28 19:41:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "get_next_line/get_next_line.h"

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
		while (get_next_line(0))
		{
			if (ft_strcmp(get_next_line(0), "sa"))
				ft_swap(stack, 'a');
			else if (ft_strcmp(get_next_line(0), "sb"))
				ft_swap(stack, 'b');
			else if (ft_strcmp(get_next_line(0), "ss"))
				ft_swap(stack, 's');
			else if (ft_strcmp(get_next_line(0), "ra"))
				ft_rotate(stack, 'a');
			else if (ft_strcmp(get_next_line(0), "rb"))
				ft_rotate(stack, 'b');
			else if (ft_strcmp(get_next_line(0), "rr"))
				ft_rotate(stack, 'r');
			else if (ft_strcmp(get_next_line(0), "rra"))
				ft_rev_rotate(stack, 'a');
			else if (ft_strcmp(get_next_line(0), "rrb"))
				ft_rev_rotate(stack, 'b');
			else if (ft_strcmp(get_next_line(0), "rrr"))
				ft_rev_rotate(stack, 'r');
			else if (ft_strcmp(get_next_line(0), "DONE"))
				exit(-1);
		}
		ft_stack_freer(&(stack->stack_a), stack->size_a);
		free(comb);
		free(stack);
	}
	return (0);
}
