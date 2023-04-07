/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:36:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/09 12:36:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

# define RED "\x1b[31m"
# define NORMAL "\x1b[m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define BLUE "\x1b[34m"
# define ERROR -1

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
}	t_stacks;

// Arg Validate
int		ft_check_invalid_args(char *str);
int		ft_check_duplicate(char *str);
int		ft_sign_after_num(char *str);
int		ft_check_empty(int argc, char *argv[]);
int		ft_isvalid(char c);

// 
void	ft_magic(t_stacks *stacks);
void	ft_3_elem(t_stacks *stacks);
int		is_sorted(t_list *head, int size);
void	ft_tiny_sort(t_stacks *stacks);
void	ft_big_sort(t_stacks *stacks, int size);

// In utilities
void	ft_freer(char **str);
void	ft_stack_freer(t_list **stack, int size);
int		ft_put_error(char *str, t_stacks *stack);
void	ft_print(t_stacks *stacks, char c);
int		*ft_create_array(t_stacks *stacks, int size);

// The Operations
void	ft_swap(t_stacks *stacks, char c);
void	ft_rev_rotate(t_stacks *stacks, char c);
void	ft_rotate(t_stacks *stacks, char c);
void	ft_push(t_stacks *stacks, char c);

#endif
