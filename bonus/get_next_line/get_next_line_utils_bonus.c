/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:19:27 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/13 17:19:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_j;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 && !s2)
		return (s1);
	str_j = (char *)ft_calloc((sizeof(char) * (len1 + len2 + 1)), 1);
	if (!str_j)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		str_j[i] = s1[i];
	while (s2[++j])
		str_j[i++] = s2[j];
	str_j[i] = '\0';
	free(s1);
	return (str_j);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)src;
	character = (unsigned char)c;
	while (*str != character)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}
