/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rev_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:41:28 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/08 18:13:43 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rev_a(t_push_swap *ps)
{
	int	i;
	int	aux;

	if (ps->len_a == 0)
		return ;
	i = ps->len_a - 1;
	aux = ps->stack_a[ps->len_a - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[i] = aux;
	if (ps->b == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb_rev_b(t_push_swap *ps)
{
	int	i;
	int	aux;

	i = ps->len_a - 1;
	aux = ps->stack_b[ps->len_a - 1];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[i] = aux;
	if (ps->b == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr_a_b(t_push_swap *ps)
{
	ps->b = 1;
	rra_rev_a(ps);
	rrb_rev_b(ps);
	ft_putstr_fd("rrr\n", 1);
	ps->b = 0;
}
