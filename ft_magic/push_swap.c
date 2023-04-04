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

void    ft_init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
}

int	ft_put_error(void)
{
	ft_putstr_fd(RED "Error\n" NORMAL, 2);
	exit(ERROR);
}

int	ft_check_empty(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_put_error();
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	char		*comb;
	t_stacks	stacks;

	if (argc > 1)
	{
		i = 1;
		ft_init_stacks(&stacks);
		comb = ft_strdup("");
		while (i < argc)
			comb = ft_strjoin(ft_strjoin(comb, argv[i++]), " ");
		if (ft_check_duplicate(comb) || ft_check_invalid_args(comb) || 
			ft_check_empty(argc, argv))
			ft_put_error();
		stacks.stack_a = ft_create_stack_a(comb);
		ft_magic(&stacks);
		free(comb);
		// ft_stack_freer(&stacks.stack_a);
		// ft_stack_freer(&stacks.stack_b);
	}
	return (0);
}
