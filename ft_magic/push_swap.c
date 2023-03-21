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

t_list	*ft_create_stack_a(char *str)
{
	char	**holder;
	t_list	*queue_a;
	t_list	*ll_a;
	int		i;
	int		c;

	i = 0;
	c = 0;
	holder = ft_split(str, ' ');
	queue_a = NULL;
	while (holder[i])
	{
		c = ft_atoi(holder[i]);
		ll_a = ft_lstnew(c);
		ft_lstadd_back(&queue_a, ll_a);
		i++;
	}
	ft_freer(holder);
	return (queue_a);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*comb;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	(void)stack_b;
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
	return (0);
}
