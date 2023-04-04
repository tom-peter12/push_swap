#include "libft.h"

int	ft_lstmax(t_list **lst)
{
	int		size;
	int		min;
	t_list	*temp;
	int		i;

	size = ft_lstsize(*lst);
	temp = *lst;
	i = 0;
	min = temp->content;
	while (i < size)
	{
		if (min < temp->content)
			min = temp->content;
		temp = temp->next;
		i++;
	}
	return (min);
}
