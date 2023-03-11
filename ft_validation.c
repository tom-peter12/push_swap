/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:44:45 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/10 14:44:46 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(char *str)
{
	char	**holder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	holder = ft_split(str, ' ');
	while (holder[i])
	{
		j = i + 1;
		while (holder[j])
		{
			if (ft_strcmp(holder[i], holder[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_isvalid(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || (c >= '0' && c <= '9')
		|| c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	ft_sign_after_num(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_invalid_args(char *str)
{
	int		i;
	char	**holder;

	i = 0;
	while (str[i])
	{
		if (ft_isvalid(str[i]))
			i++;
		else
			return (1);
	}
	holder = ft_split(str, ' ');
	while (*holder)
	{
		if (!ft_strcmp(*holder, "0"))
			holder++;
		else
		{
			if (ft_sign_after_num(*holder) || !ft_atoi(*holder))
				return (1);
			holder++;
		}
	}
	return (0);
}
