/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:41 by tpetros           #+#    #+#             */
/*   Updated: 2022/10/15 16:36:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*find))
		return ((char *)str);
	if (!str && len == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (str[i + j] == find[j] && i + j < len)
			{
				if (find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
