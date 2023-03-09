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

#include "push_swap.h"

int	ft_check_args(int arg, char *args)
{
	char	**holder;
	int		i;

	holder = ft_split(args, ' ');
	i = 0;
	if (arg < 2)
	{
		ft_putstr_fd(RED "Error\n" NORMAL, 2);
		return (ERROR);
	}
	while (*holder)
	{
		if (!ft_strncmp(*holder, "0", 1))
			holder++;
		else
		{
			if (!ft_atoi(*holder) )
			{
				ft_putstr_fd(RED "Error\n" NORMAL, 2);
				return (ERROR);
			}
			holder++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*queue_a;
	t_list	*ll_a;
	char	*comb;
	int		i;
	char	**holder;

	i = 1;
	comb = ft_strdup("");
	while (i < argc)
	{
		comb = ft_strjoin(comb, argv[i]);
		comb = ft_strjoin(comb, " ");
		i++;
	}
	comb = ft_strtrim(comb, " ");
	if (ft_check_args(argc, comb))
		return (ERROR);
	holder = ft_split(comb, ' ');
	while (*holder)
	{
		ll_a = ft_lstnew(*holder);
		ft_lstadd_back(&queue_a, ll_a);
		holder++;
	}
	ll_a = ft_lstnew(*holder);
	ft_lstadd_back(&queue_a, ll_a);
	return (0);
}
