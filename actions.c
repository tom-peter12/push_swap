/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:35:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/09 12:36:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *top, t_list *below_top)
{
	int	temp;

	temp = top->content;
	top->content = below_top->content;
	below_top->content = temp;
}

void	ft_push(t_list *head_a, t_list *head_b)
{
		
}

void	ft_rotate(t_list *head)
{
	
}

void	ft_reverse_rotate(t_list head)
{
	
}
