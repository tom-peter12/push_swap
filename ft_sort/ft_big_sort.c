/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:55:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/07 10:55:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_to_b(t_stacks *s, int min, int mid, int max)
{
	while (s->size_a > 2)
	{
		if (s->stack_a->content > mid && s->stack_a->content != min &&
			s->stack_a->content != max)
		{
			ft_push(s, 'b');
			ft_rotate(s, 'b');
		}
		else if (s->stack_a->content <= mid && s->stack_a->content != min &&
			s->stack_a->content != max)
			ft_push(s, 'b');
		else
			ft_rotate(s, 'a');
	}
	if (s->stack_a->content == min)
		ft_rotate(s, 'a');
}

int	ft_calc_score_a(t_stacks *stacks, int num)
{
	int		score_a;
	t_list	*temp;

	score_a = 0;
	temp = stacks->stack_a;
	while (num > temp->content || temp->prev->content > num)
	{
		temp = temp->next;
		score_a++;
	}
	if (score_a < stacks->size_a - score_a)
		return (score_a);
	else
		return (score_a - stacks->size_a);
}

void	ft_calc_score(t_list *temp, int i, t_stacks *s)
{
	int	score_a;
	int	score_b;

	score_a = ft_calc_score_a(s, temp->content);
	if (i < s->size_b - i)
		score_b = i;
	else
		score_b = i - s->size_b;
	if ((score_a > 0 && score_b > 0)
		|| (score_a < 0 && score_b < 0))
	{
		if (ft_abs(score_a) > ft_abs(score_b))
			temp->rot_score = ft_abs(score_a);
		else
			temp->rot_score = ft_abs(score_b);
	}
	else
		temp->rot_score = ft_abs(score_b) + ft_abs(score_a);
}

void	ft_lets_sort(t_stacks *stacks)
{
	t_list	*temp;
	int		i;
	int		position;
	t_list	*min_score;

	temp = stacks->stack_b;
	while (i < stacks->size_b)
	{
		ft_calc_score(temp, i, stacks);
		temp = temp->next;
		i++;
	}
	min_score = ft_find_min_score(stacks, &position);
	ft_rot_and_push_ab(stacks, min_score, position);
}

void	ft_big_sort(t_stacks *stacks, int size)
{
	int	min;
	int	max;
	int	mid;
	int	*temp;

	temp = ft_create_array(stacks, size);
	min = ft_lstmin(&stacks->stack_a, stacks->size_a);
	max = ft_lstmax(&stacks->stack_a, stacks->size_a);
	mid = temp[(size - 1) / 2];
	ft_push_to_b(stacks, min, mid, max);
	while (stacks->stack_b)
		ft_lets_sort(stacks);
	ft_final_rot(stacks);
	free(temp);
}
