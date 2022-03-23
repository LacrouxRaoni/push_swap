/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:09:48 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/23 11:15:29 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_min_3(t_push_swap *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
		sa_swap_a(ps);
	while (ps->stack_a[2] < ps->stack_a[0])
		rra_rev_a(ps);
	if (is_stack_sorted(ps) == 0)
	{
		rra_rev_a(ps);
		sa_swap_a(ps);
	}
}	

static void	validate_pb(t_push_swap *ps)
{
	while (ps->len_a > 3)
	{
		if (ps->size == 4)
		{
			if (ps->stack_a[0] == ps->min_a)
				pb_push_b(ps);
			else
				ra_rotate_a(ps);
		}
		else
		{
			if (ps->stack_a[0] == ps->min_a || ps->stack_a[0] == ps->min_a + 1)
				pb_push_b(ps);
			else
				ra_rotate_a(ps);
		}
	}
}

void	sort_stack_min_5(t_push_swap *ps)
{
	int	i;
	int	*pos;

	pos = malloc(sizeof(int *) * ps->size);
	define_position_stack_a(ps, pos);
	i = -1;
	while (++i < ps->len_a)
		ps->stack_a[i] = pos[i];
	free (pos);
	find_max_min_stack_a(ps);
	validate_pb(ps);
	if (ps->len_b == 2 && ps->stack_b[0] < ps->stack_b[1])
		sb_swap_b(ps);
	sort_stack_min_3(ps);
	pa_push_a(ps);
	pa_push_a(ps);
}
