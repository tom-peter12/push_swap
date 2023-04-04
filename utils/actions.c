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

#include "../includes/push_swap.h"


// Swap function

void	ft_swap_(t_list **head)
{
	int		temp;

	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
}

void	ft_swap(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a && stacks->stack_a->next)
	{
		ft_swap_(&stacks->stack_a);
		ft_putstr(BLUE"sa\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_b && stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_b);
		ft_putstr(BLUE"sb\n"NORMAL);
	}
	if (c == 's' && stacks->stack_a && stacks->stack_a->next && stacks->stack_b && stacks->stack_b->next)
	{
		ft_swap_(&stacks->stack_a);
		ft_swap_(&stacks->stack_b);
		ft_putstr(BLUE"ss\n"NORMAL);
	}
}


// rotate function
void	ft_rotate_(t_list **first)
{
	t_list	*second;

	second = (*first)->next;
	(*first) = second;
}

void	ft_rotate(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a)
	{
		ft_rotate_(&stacks->stack_a);
		ft_putstr(MAGENTA"ra\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_b)
	{
		ft_rotate_(&stacks->stack_b);
		ft_putstr(MAGENTA"rb\n"NORMAL);
	}
	if (c == 'r' && stacks->stack_a && stacks->stack_b)
	{
		ft_rotate_(&stacks->stack_a);
		ft_rotate_(&stacks->stack_b);
		ft_putstr(MAGENTA"rr\n"NORMAL);
	}
}


// reverse rotate
void	ft_rev_rotate_(t_list **first, int stack_size)
{
	int		j;
	t_list	*temp;

	j = 0;
	temp = *first;
	while (j < stack_size - 1)
	{
		temp = temp->next;
		j++;
	}
	(*first) = temp;
}

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_a)
	{
		ft_rev_rotate_(&stacks->stack_a, stacks->size_a);
		ft_putstr(GREEN"rra\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_b, stacks->size_b);
		ft_putstr(GREEN"rrb\n"NORMAL);
	}
	if (c == 'r' && stacks->stack_a && stacks->stack_b)
	{
		ft_rev_rotate_(&stacks->stack_a, stacks->size_a);
		ft_rev_rotate_(&stacks->stack_b, stacks->size_b);
		ft_putstr(GREEN"rrr\n"NORMAL);
	}
}
