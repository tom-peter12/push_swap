/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:55:13 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 15:55:14 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_duplicate(char *str)
{
	char	**holder;
	int		i;
	int		j;

	i = 0;
	holder = ft_split(str, ' ');
	while (holder[i])
	{
		j = i + 1;
		if (ft_strlen(holder[i]) != 2 && ft_atoi(holder[i]) == -1)
		{
			ft_freer(holder);
			return (1);
		}
		while (holder[j])
		{
			if (ft_atoi(holder[i]) == ft_atoi(holder[j]))
			{
				ft_freer(holder);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_freer(holder);
	return (0);
}
