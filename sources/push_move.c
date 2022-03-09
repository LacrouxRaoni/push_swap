/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:47:45 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/20 15:14:18 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_push_a(t_push_swap *ps)
{
	int	i;

	i = ps->top - 1;
	if (ps->len_b == 0 || ps->len_a == ps->top)
		return ;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	i = 0;
	while (i < ps->len_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i] = 0;
	ps->len_b--;
	ps->len_a++;
	ft_putstr_fd("pa\n", 1);
}

void	pb_push_b(t_push_swap *ps)
{
	int	i;

	i = ps->top - 1;
	if (ps->len_a == 0 || ps->len_b == ps->top)
		return ;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	i = 0;
	while (i < ps->top - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i] = 0;
	ps->len_a--;
	ps->len_b++;
	ft_putstr_fd("pb\n", 1);
}
