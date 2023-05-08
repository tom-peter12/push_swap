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

#include "../../includes/push_swap.h"

int	ft_after_error(char **str)
{
	ft_freer(str);
	return (1);
}

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
		while (holder[j])
		{
			if (ft_atoi(holder[i]) == ft_atoi(holder[j]))
				return (ft_after_error(holder));
			j++;
		}
		i++;
	}
	ft_freer(holder);
	return (0);
}
