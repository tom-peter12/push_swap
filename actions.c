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

void	ft_swap(t_list *top, t_list *below_top, char *str)
{
	int	temp;

	temp = top->content;
	top->content = below_top->content;
	below_top->content = temp;
	ft_compare(str);
}

void	ft_rotate(t_list **head, char *str)
{
	int		content;
	t_list	*ll_a;

	content = (*head)->content;
	ll_a = ft_lstnew(content);
	*head = pop_front(head);
	ft_lstadd_back(head, ll_a);
	ft_compare(str);
}

void	ft_reverse_rotate(t_list **head, char *str)
{
	int		content;
	t_list	*ll_a;

	ll_a = ft_lstlast(*head);
	content = ll_a->content;
	ll_a = ft_lstnew(content);
	pop_back(*head);
	ft_lstadd_front(head, ll_a);
	ft_compare(str);
}

void	ft_push(t_list **head_a, t_list **head_b, char *str)
{
	int		content;
	t_list	*ll_a;

	content = (*head_a)->content;
	ll_a = ft_lstnew(content);
	*head_a = pop_front(head_a);
	ft_lstadd_front(head_b, ll_a);
	ft_compare(str);
}
