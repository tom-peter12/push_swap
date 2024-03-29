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

void	ft_double_actions(char *line, t_stacks *stack, char *str)
{
	if (!ft_strcmp(line, "ss\n"))
		ft_swap(stack, 's', 0);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate(stack, 'r', 0);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rev_rotate(stack, 'r', 0);
	else
	{
		ft_putstr_fd("INVALID INSTRUCTION ...\n", 2);
		free(line);
		free(str);
		ft_stack_freer(&(stack->stack_a), stack->size_a);
		ft_stack_freer(&(stack->stack_b), stack->size_b);
		free(stack);
		exit(ERROR);
	}
}

void	ft_checker(char *line, t_stacks *stacks, char *str)
{
	if (!(ft_strcmp(line, "sa\n")))
		ft_swap(stacks, 'a', 0);
	else if (!(ft_strcmp(line, "sb\n")))
		ft_swap(stacks, 'b', 0);
	else if (!(ft_strcmp(line, "pa\n")))
		ft_push(stacks, 'a', 0);
	else if (!(ft_strcmp(line, "pb\n")))
		ft_push(stacks, 'b', 0);
	else if (!(ft_strcmp(line, "ra\n")))
		ft_rotate(stacks, 'a', 0);
	else if (!(ft_strcmp(line, "rb\n")))
		ft_rotate(stacks, 'b', 0);
	else if (!(ft_strcmp(line, "rra\n")))
		ft_rev_rotate(stacks, 'a', 0);
	else if (!(ft_strcmp(line, "rrb\n")))
		ft_rev_rotate(stacks, 'b', 0);
	else
		ft_double_actions(line, stacks, str);
}

int	ft_read_instruction(t_stacks *stack, char *str)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if ((ft_strcmp(line, "DONE\n") == 0))
		{
			free(line);
			return (1);
		}
		else if (!ft_strcmp(line, "\n"))
			continue ;
		ft_checker(line, stack, str);
		free(line);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	char		*comb;
	t_stacks	*stack;

	if (argc > 1)
	{
		stack = (t_stacks *) malloc(sizeof(t_stacks));
		i = 1;
		comb = ft_strdup("");
		while (i < argc)
			comb = ft_strjoin(ft_strjoin(comb, argv[i++]), " ");
		if (ft_arg_check(argc, argv, comb))
			ft_put_error(comb, stack);
		ft_create_stack_a(comb, stack);
		if (ft_read_instruction(stack, comb) && stack->size_a > 0
			&& is_sorted(&stack->stack_a) && stack->size_b == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(comb);
		ft_freerrr(stack);
		free(stack);
	}
	return (0);
}
