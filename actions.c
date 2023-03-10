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

t_list	*pop_front(t_list *head) 
{
	if(head != NULL)
	{
		t_list*	temp;

		temp = head;
		head = head->next; 
		free(temp); 
	}
	return (head);
}

void pop_back(t_list *head) 
{
	if(head != NULL) 
	{
		if(head->next == NULL)
			head = NULL;
		else
		{
			t_list* temp = head;
			while(temp->next->next != NULL)
				temp = temp->next;

			t_list* lastNode = temp->next;
			temp->next = NULL;
			free(lastNode); 
		}
  	}
}

void	ft_swap(t_list *top, t_list *below_top)
{
	int	temp;

	temp = top->content;
	top->content = below_top->content;
	below_top->content = temp;
}

void	ft_rotate(t_list *head)
{
	int		content;
	t_list	*ll_a;

	content = head->content;
	ll_a = ft_lstnew(content);
	head = pop_front(head);
	ft_lstadd_back(&head, ll_a);
	
	// while (head)
	// {
	// 	ft_printf("||%d||\n", head->content);
	// 	head = head->next;
	// }
}

void	ft_reverse_rotate(t_list *head)
{
	int		content;
	t_list	*ll_a;

	ll_a = ft_lstlast(head);
	content = ll_a->content;
	ll_a = ft_lstnew(content);
	pop_back(head);
	ft_lstadd_front(&head, ll_a);
	while (head->next)
	{
		ft_printf("||%d||\n", head->content);
		head = head->next;
	}
}

// void	ft_push(t_list *head_a, t_list *head_b)
// {
		
// }
