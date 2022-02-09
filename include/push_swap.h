/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:56 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/07 22:18:02 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483647

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	top;
	int	len_a;
	int	len_b;
	int	b;
}	t_push_swap;

int		push_swap(char *argv[], t_push_swap *ps, int argc);
int		check_num_argv(char **argv);
int		check_rep_num_argv(char **argv, int argc, t_push_swap *ps);
void	sa_swap_a(t_push_swap *ps);
void	sb_swap_b(t_push_swap *ps);
void	ss_sa_n_sb(t_push_swap *ps);
void	pa_push_a(t_push_swap *ps);
void	pb_push_b(t_push_swap *ps);
void	ra_rotate_a(t_push_swap *ps);
void	rb_rotate_b(t_push_swap *ps);
void	rr_ra_rb(t_push_swap *ps);
void	rra_rev_a(t_push_swap *ps);
void	rrb_rev_b(t_push_swap *ps);
void	rrr_a_b(t_push_swap *ps);
void	free_push_swap(t_push_swap *ps);

#endif
