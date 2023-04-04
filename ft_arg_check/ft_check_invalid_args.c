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

static void	util(char *str, int i)
{
	while (str[i])
	{
		if (ft_isvalid(str[i]))
			i++;
		else
			exit(1);
	}
}

int	ft_check_invalid_args(char *str)
{
	int		i;
	char	**holder;

	i = 0;
	util(str, i);
	holder = ft_split(str, ' ');
	i = 0;
	while (holder[i])
	{
		if (!ft_strcmp(holder[i], "0"))
			i++;
		else
		{
			if (ft_sign_after_num(holder[i]) || !ft_atoi(holder[i]))
				return (1);
			i++;
		}
	}
	ft_freer(holder);
	return (0);
}
