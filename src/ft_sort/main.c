#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	char		*comb;
	t_stacks	*stack;

	if (argc > 1)
	{
		stack = malloc(sizeof(t_stacks));
		i = 1;
		comb = ft_strdup("");
		while (i < argc)
			comb = ft_strjoin(ft_strjoin(comb, argv[i++]), " ");
		if (ft_check_empty(argc, argv) || ft_check_invalid_args(comb)
			|| ft_check_duplicate(comb))
			ft_put_error(comb, stack);
		ft_create_stack_a(comb, stack);
		ft_magic(stack);
		ft_stack_freer(&(stack->stack_a), stack->size_a);
		free(comb);
		free(stack);
	}
	return (0);
}
