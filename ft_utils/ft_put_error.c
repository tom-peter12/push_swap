/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:11:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 16:12:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_put_error(char *str, t_stacks *stack)
{
	free(str);
	free(stack);
	ft_putstr_fd(RED "Error\n" NORMAL, 2);
	exit(ERROR);
}
