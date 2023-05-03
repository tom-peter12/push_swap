/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:13:55 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/25 12:13:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_find_min_score(t_stacks *ab, int *position)
{
	int		i;
	t_list	*temp;
	t_list	*min_score_elem;

	i = 1;
	*position = 0;
	temp = ab->stack_b->next;
	min_score_elem = ab->stack_b;
	while (i < ab->size_b)
	{
		if (temp->rot_score < min_score_elem->rot_score && temp)
		{
			*position = i;
			min_score_elem = temp;
		}
		i++;
		temp = temp->next;
	}
	return (min_score_elem);
}

void	ft_rot_ab(t_stacks *ab, int *score_a, int *score_b)
{
	while (*score_b > 0 && *score_a > 0)
	{
		ft_rotate(ab, 'r');
		--*score_b;
		--*score_a;
	}
	while (*score_a > 0)
	{
		ft_rotate(ab, 'a');
		--*score_a;
	}
	while (*score_b > 0)
	{
		ft_rotate(ab, 'b');
		--*score_b;
	}
}

void	ft_rev_rot_ab(t_stacks *ab, int	*score_a, int *score_b)
{
	while (*score_b < 0 && *score_a < 0)
	{
		ft_rev_rotate(ab, 'r');
		++*score_b;
		++*score_a;
	}
	while (*score_a < 0)
	{
		ft_rev_rotate(ab, 'a');
		++*score_a;
	}
	while (*score_b < 0)
	{
		ft_rev_rotate(ab, 'b');
		++*score_b;
	}
}

void	ft_rot_and_push_ab(t_stacks *ab, t_list *min_score, int position)
{
	int	score_a;
	int	score_b;

	score_a = ft_calc_score_a(ab, min_score->content);
	if (position < ab->size_b - position)
		score_b = position;
	else
		score_b = position - ab->size_b;
	if (score_b > 0 || score_a > 0)
		ft_rot_ab(ab, &score_a, &score_b);
	if (score_b < 0 || score_a < 0)
		ft_rev_rot_ab(ab, &score_a, &score_b);
	ft_push(ab, 'a', 1);
}

void	ft_final_rot(t_stacks *stack)
{
	t_list	*temp;
	int		i;
	int		max_a;

	i = 0;
	temp = stack->stack_a;
	max_a = ft_lstmax(&stack->stack_a, stack->size_a);
	while (i < stack->size_a && temp->content < max_a)
	{
		temp = temp->next;
		i++;
	}
	while (!is_sorted(&stack->stack_a))
	{
		if (i < stack->size_a - i)
			ft_rotate(stack, 'a');
		else
			ft_rev_rotate(stack, 'a');
	}
}
