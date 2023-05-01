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

int	do_commands(char *line, t_stacks *stacks)
{
	if (!(ft_strcmp(line, "sa\n")))
	{
		ft_swap_(&stacks->stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "sb\n")))
	{
		ft_swap_(&stacks->stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pa\n")))
	{
		ft_push_(&stacks->stack_a, &stacks->stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pb\n")))
	{
		ft_push_(&stacks->stack_b, &stacks->stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "ra\n")))
	{
		ft_rotate_(&stacks->stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rb\n")))
	{
		ft_rotate_(&stacks->stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rra\n")))
	{
		ft_rev_rotate_(&stacks->stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb\n")))
	{
		ft_rev_rotate_(&stacks->stack_b);
		return (0);
	}
	return (1);
}

void	print_checker_res(t_stacks *stack)
{
	if (is_sorted(&stack->stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (stack->stack_a)
		ft_stack_freer(&(stack->stack_a), stack->size_a);
	if (stack->stack_b)
		ft_stack_freer(&(stack->stack_b), stack->size_b);
}

int	main(int argc, char *argv[])
{
	int			i;
	char		*comb;
	t_stacks	*stack;
	char		*line;

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
		while (i)
		{
			line = get_next_line(0);
			if (do_commands(line, stack))
			{
				i = 0;
				ft_put_error(line, stack);
				break;
			}
		}
		print_checker_res(stack);
		free(comb);
		free(stack);
	}
	return (0);
}
