/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:55:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/17 11:55:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *head)
{
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_case_two(t_list **head)
{
	t_var	var_holder;

	var_holder.one = (*head)->content;
	var_holder.two = (*head)->next->content;
	if (var_holder.one > var_holder.two)
		ft_swap((*head), ((*head)->next), "sa");
}

void	ft_case_three(t_list **head)
{
	t_var	var;

	var.one = (*head)->content;
	var.two = (*head)->next->content;
	var.three = (*head)->next->next->content;
	if (var.one > var.two && var.two < var.three && var.one < var.three)
		ft_swap((*head), ((*head)->next), "sa");
	else if (var.one > var.two && var.one > var.three && var.two < var.three)
		ft_rotate(head, "ra");
	else if (var.one < var.two && var.one > var.three && var.two > var.three)
		ft_reverse_rotate(head, "rra");
	else if (var.one > var.two && var.one > var.three && var.two > var.three)
	{
		ft_swap((*head), ((*head)->next), "sa");
		ft_reverse_rotate(head, "rra");
	}
	else
	{
		ft_swap((*head), ((*head)->next), "sa");
		ft_rotate(head, "ra");
	}
}

// void	ft_case_big(t_list **head_a, t_list **head_b)
// {

// }

void	ft_magic(t_list **head, t_list **stack_b_head)
{
	(void)stack_b_head;
	if (is_sorted(*head))
		return ;
	if (ft_lstsize((*head)) == 2)
		ft_case_two(head);
	else if (ft_lstsize((*head)) == 3)
		ft_case_three(head);
	// else
	// 	ft_case_big(head, *stack_b_head);
}
