/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:38:13 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/14 23:32:40 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min_stack_a(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->min = ps->stack_a[0];
	while (i < ps->top)
	{
		if (ps->min > ps->stack_a[i])
			ps->min = ps->stack_a[i];
		i++;
	}
	i = 0;
	ps->max = ps->stack_a[0];
	while (i < ps->top)
	{
		if (ps->max < ps->stack_a[i])
			ps->max = ps->stack_a[i];
		i++;
	}
}

void	find_max_min_stack_b(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->min = ps->stack_b[0];
	while (i < ps->top)
	{
		if (ps->min > ps->stack_b[i])
			ps->min = ps->stack_b[i];
		i++;
	}
	i = 0;
	ps->max = ps->stack_b[0];
	while (i < ps->top)
	{
		if (ps->max < ps->stack_b[i])
			ps->max = ps->stack_b[i];
		i++;
	}
}
