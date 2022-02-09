/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:45:06 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/07 22:25:19 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap_a(t_push_swap *ps)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	if (ps->len_a < 2)
		return ;
	aux = ps->stack_a[i];
	ps->stack_a[i] = ps->stack_a[i + 1];
	ps->stack_a[i + 1] = aux;
	if (ps->b == 0)
		ft_putstr_fd("sa\n", 1);
}

void	sb_swap_b(t_push_swap *ps)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	if (ps->len_b < 2)
		return ;
	aux = ps->stack_b[i];
	ps->stack_b[i] = ps->stack_b[i + 1];
	ps->stack_b[i + 1] = aux;
	if (ps->b == 0)
		ft_putstr_fd("sb\n", 1);
}

void	ss_sa_n_sb(t_push_swap *ps)
{
	ps->b = 1;
	sa_swap_a(ps);
	sb_swap_b(ps);
	ft_putstr_fd("ss\n", 1);
	ps->b = 0;
}
