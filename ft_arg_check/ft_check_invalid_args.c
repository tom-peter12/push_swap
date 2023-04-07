/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:54:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 15:54:04 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	util(char *str, int i)
{
	while (str[i])
	{
		if (ft_isvalid(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_invalid_args(char *str)
{
	int		i;
	char	**holder;

	i = 0;
	if (util(str, i) == 1)
		return (1);
	holder = ft_split(str, ' ');
	i = 0;
	while (holder[i])
	{
		if (!ft_strcmp(holder[i], "0"))
			i++;
		else
		{
			if (ft_sign_after_num(holder[i]) || !ft_atoi(holder[i]))
			{
				ft_freer(holder);
				return (1);
			}
			i++;
		}
	}
	ft_freer(holder);
	return (0);
}
