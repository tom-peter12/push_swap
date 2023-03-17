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

# define RED "\x1b[31m"
# define NORMAL "\x1b[m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define BLUE "\x1b[34m"
# define ERROR 64

int		ft_check_invalid_args(char *str);
int		ft_check_duplicate(char *str);
t_list	*ft_create_stack_a(char *str);
void	ft_rotate(t_list **head);
void	ft_reverse_rotate(t_list **head);
void	ft_swap(t_list *top, t_list *below_top);

#endif
