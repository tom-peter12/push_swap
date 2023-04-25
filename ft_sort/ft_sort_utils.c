/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:47:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/05 13:47:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	is_sorted(t_list *head, int size)
// {
// 	t_list	*current;
// 	int		i;

// 	current = head;
// 	i = 1;
// 	if (head == NULL || head->next == NULL)
// 		return (1);
// 	while (i < size)
// 	{
// 		if (current->content > current->next->content)
// 			return (0);
// 		current = current->next;
// 		i++;
// 	}
// 	return (1);
// }

int	is_sorted(t_list **first)
{
	t_list	*temp;
	t_list	*last;

	temp = *first;
	last = (*first)->prev;
	if (!(*first))
		return (-1);
	while (temp != last)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
