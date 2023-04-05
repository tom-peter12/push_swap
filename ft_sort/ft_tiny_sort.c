#include "../includes/push_swap.h"

void	ft_sort5(t_stacks *stacks)
{
	int	min;
	int	max;

	min = ft_find_min(&stacks->stack_a, stacks->size_a);
	max = ft_find_max(&stacks->stack_a, stacks->size_a);
	while (stacks->size_a != 3)
	{
		if (stacks->stack_a->content == max || stacks->stack_a->content == min)
			ft_rotate(stacks, 'a');
		else
			ft_push(stacks, 'b');
	}
	ft_3_elem(stacks);
	ft_rev_rotate(stacks, 'a');
	if (stacks->stack_b->content < stacks->stack_b->next->content)
		ft_swap(stacks, 'b');
	while (stacks->stack_b)
	{
		while ((stacks->stack_b->content > stacks->a->content) || stacks->a->prev->content > stacks->stack_b->content)
			ft_rev_rotate(stacks, 'a');
		ft_push(stacks, 'a');
	}
	while (ft_check_sort(&stacks->stack_a))
		ft_rev_rotate(stacks, 'a');
}
