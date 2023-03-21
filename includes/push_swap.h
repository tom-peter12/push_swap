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
# include "../libft/libft.h"

# define RED "\x1b[31m"
# define NORMAL "\x1b[m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define BLUE "\x1b[34m"
# define ERROR 64

typedef struct s_var
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;
}	t_var;

int		ft_check_invalid_args(char *str);
int		ft_check_duplicate(char *str);
t_list	*ft_create_stack_a(char *str);
void	ft_rotate(t_list **head, char *str);
void	ft_reverse_rotate(t_list **head, char *str);
void	ft_swap(t_list *top, t_list *below_top, char *str);
void	ft_magic(t_list **head, t_list **stack_b_head);
void	ft_push(t_list **head_a, t_list **head_b, char *str);
t_list	*pop_front(t_list **head);
void	pop_back(t_list *head);
void	ft_compare(char *str);
void	ft_freer(char **str);

#endif
