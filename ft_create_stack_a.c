/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_queue_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:17:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/10 17:17:52 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (queue_a);
}