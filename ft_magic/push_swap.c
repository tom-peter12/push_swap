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

int	main(int argc, char *argv[])
{
	int		i;
	char	*comb;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	stack_b = NULL;
	comb = ft_strdup("");
	while (i < argc)
	{
		comb = ft_strjoin(comb, argv[i]);
		comb = ft_strjoin(comb, " ");
		i++;
	}
	if (ft_check_duplicate(comb) || ft_check_invalid_args(comb))
	{
		ft_putstr_fd(RED "Error\n" NORMAL, 2);
		return (ERROR);
	}
	stack_a = ft_create_stack_a(comb);
	free(comb);
	ft_magic(&stack_a, &stack_b);
	ft_stack_freer(&stack_a);
	ft_stack_freer(&stack_b);
	return (0);
}
