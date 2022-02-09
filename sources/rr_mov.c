/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:29 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/08 17:26:37 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(t_push_swap *ps)
{
	int	i;
	int	aux;

	if (ps->len_a == 0)
		return ;
	i = 0;
	aux = ps->stack_a[i];
	while (i < ps->len_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i] = aux;
	if (ps->b == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rb_rotate_b(t_push_swap *ps)
{
	int	i;
	int	aux;

	if (ps->len_b == 0)
		return ;
	i = 0;
	aux = ps->stack_b[i];
	while (i < ps->len_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i] = aux;
	if (ps->b == 0)
		ft_putstr_fd("rb\n", 1);
}

void	rr_ra_rb(t_push_swap *ps)
{
	ps->b = 1;
	ra_rotate_a(ps);
	rb_rotate_b(ps);
	ft_putstr_fd("rr\n", 1);
	ps->b = 0;
}
