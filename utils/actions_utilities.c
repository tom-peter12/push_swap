/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:51:00 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/17 14:51:01 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*pop_front(t_list **head)
{
	t_list	*temp;

	if (head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return (*head);
}

void	pop_back(t_list *head)
{
	t_list	*temp;
	t_list	*lastnode;

	if (head != NULL)
	{
		temp = head;
		if (head->next == NULL)
			head = NULL;
		else
		{
			while (temp->next->next != NULL)
				temp = temp->next;
			lastnode = temp->next;
			temp->next = NULL;
			free(lastnode);
		}
	}
}

void	ft_compare(char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_putstr(YELLOW"sa\n"NORMAL);
	else if (!ft_strcmp(str, "sb"))
		ft_putstr(YELLOW"sb\n"NORMAL);
	else if (!ft_strcmp(str, "ra"))
		ft_putstr(GREEN"ra\n"NORMAL);
	else if (!ft_strcmp(str, "rb"))
		ft_putstr(GREEN"rb\n"NORMAL);
	else if (!ft_strcmp(str, "rra"))
		ft_putstr(MAGENTA"rra\n"NORMAL);
	else if (!ft_strcmp(str, "rrb"))
		ft_putstr(MAGENTA"rrb\n"NORMAL);
	else if (!ft_strcmp(str, "pa"))
		ft_putstr(BLUE"pa\n"NORMAL);
	else if (!ft_strcmp(str, "pb"))
		ft_putstr(BLUE"pb\n"NORMAL);
	else if (!ft_strcmp(str, "ss"))
		ft_putstr(YELLOW"ss\n"NORMAL);
	else if (!ft_strcmp(str, "rr"))
		ft_putstr(GREEN"rr\n"NORMAL);
	else if (!ft_strcmp(str, "rrr"))
		ft_putstr(MAGENTA"rrr\n"NORMAL);
}
