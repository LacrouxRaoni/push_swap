/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:38:13 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/18 18:51:51 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min_stack_a(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->min_a = ps->stack_a[0];
	while (i < ps->len_a)
	{
		if (ps->min_a > ps->stack_a[i])
		{
			ps->min_a = ps->stack_a[i];
			ps->pos_min_a = i;
		}
		i++;
	}
	i = 0;
	ps->max_a = ps->stack_a[0];
	while (i < ps->len_a)
	{
		if (ps->max_a < ps->stack_a[i])
		{
			ps->max_a = ps->stack_a[i];
			ps->pos_max_a = i;
		}
		i++;
	}
}

void	find_max_min_stack_b(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->min_b = ps->stack_b[0];
	while (i < ps->len_b)
	{
		if (ps->min_b > ps->stack_b[i])
		{
			ps->min_b = ps->stack_b[i];
			ps->pos_min_b = i;
		}
		i++;
	}
	i = 0;
	ps->max_b = ps->stack_b[0];
	while (i < ps->len_b)
	{
		if (ps->max_b < ps->stack_b[i])
		{
			ps->max_b = ps->stack_b[i];
			ps->pos_max_b = i;
		}
		i++;
	}
}
