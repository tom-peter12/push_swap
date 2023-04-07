#include "../includes/push_swap.h"

void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int *ft_create_array(t_stacks *stacks, int size)
{
	t_list	*temp;
	int		*arr;
	int		i;

	arr = (int *) malloc(sizeof(int) * size + 1);
	if (!arr)
		return (NULL);
	temp = stacks->stack_a;
	i = 0;
	while (i < size)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_array(arr, size);
	return (arr);
}
