/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: tpetros <tpetros@student.42abudhabi.ae>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:42 by tomas             #+#    #+#             */
/*   Updated: 2023/03/22 20:13:50 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stacks *ab)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = ab->stack_a;
	printf ("a = ");
	while (i < ab->size_a)
	{
		printf ("%d ",tmp->content);
		tmp = tmp->next;
		i++;
	}
	printf("\n");
}

t_list	*ft_create_stack_a(char *str)
{
	char		**holder;
	t_stacks	stack;
	t_list		*ll_a;
	int			i;
	int			c;

	i = 0;
	c = 0;
	holder = ft_split(str, ' ');
	stack.stack_a = NULL;
	while (holder[i])
	{
		c = ft_atoi(holder[i]);
		ll_a = ft_lstnew(c);
		ft_lstadd_back(&stack.stack_a, ll_a);
		i++;
	}
	stack.size_a = i;
	ft_freer(holder);
	return (stack.stack_a);
}

