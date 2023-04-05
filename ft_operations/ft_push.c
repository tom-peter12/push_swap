#include "../includes/push_swap.h"

void	ft_push_(t_list **to, t_list **from)
{
	t_list	*tmp_from;

	tmp_from = NULL;
	if ((*from) != (*from)->next)
	{
		tmp_from = (*from)->next;
		tmp_from->prev = (*from)->prev;
		(*from)->prev->next = tmp_from;
	}
	if (!(*to))
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = tmp_from;
}

void	ft_push(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->stack_b)
	{
		ft_push_(&stacks->stack_a, &stacks->b);
		stacks->size_a++;
		stacks->size_b--;
		ft_putstr(YELLOW"pa\n"NORMAL);
	}
	if (c == 'b' && stacks->stack_a)
	{
		ft_push_(&stacks->b, &stacks->stack_a);
		stacks->size_a--;
		stacks->size_b++;
		ft_putstr(YELLOW"pb\n"NORMAL);
	}
}
