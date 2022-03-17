/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:23:10 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/15 15:29:16 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_max_to_a(t_push_swap *ps)
{
	while (ps->len_b > 0)
	{
		if (ps->stack_b[0] == ps->max_b)
		{
			pa_push_a(ps);
			return (0);
		}
		else
		{
			if (ps->pos_max_b < ps->len_b / 2)
				rb_rotate_b(ps);
			else
				rrb_rev_b(ps);
		}
	}
	return (0);
}

static int	push_min_to_a(t_push_swap *ps)
{
	while (ps->len_b > 0)
	{
		if (ps->stack_b[0] == ps->min_b)
		{
			pa_push_a(ps);
			ra_rotate_a(ps);
			return (0);
		}
		else
		{
			if (ps->pos_min_b < ps->len_b / 2)
				rb_rotate_b(ps);
			else
				rrb_rev_b(ps);
		}
	}
	return (0);
}

static int	check_short_way(t_push_swap *ps,
	int min_to_botton, int max_to_botton, int j)
{
	find_max_min_stack_b(ps);
	min_to_botton = ps->len_b - ps->pos_min_b;
	max_to_botton = ps->len_b - ps->pos_max_b;
	if (ps->pos_min_b < ps->pos_max_b
		&& ps->pos_min_b < min_to_botton && ps->pos_min_b < max_to_botton)
		push_min_to_a(ps);
	else if (min_to_botton < ps->pos_min_b
		&& min_to_botton < ps->pos_max_b && min_to_botton < max_to_botton)
		push_min_to_a(ps);
	else if (ps->pos_max_b < ps->pos_min_b
		&& ps->pos_max_b < min_to_botton && ps->pos_max_b < max_to_botton)
	{
		push_max_to_a(ps);
		j++;
	}
	else if (max_to_botton < ps->pos_min_b
		&& max_to_botton < ps->pos_max_b && max_to_botton < min_to_botton)
	{
		push_max_to_a(ps);
		j++;
	}
	else
		push_min_to_a(ps);
	return (j);
}

int	sort_stack_b(t_push_swap *ps)
{
	int	min_to_botton;
	int	max_to_botton;
	int	j;

	j = 0;
	while (ps->len_b > 0)
	{
		min_to_botton = 0;
		max_to_botton = 0;
		check_short_way(ps, min_to_botton, max_to_botton, j);
	}
	if (ps->len_b == 0)
	{
		while (j > 0)
		{
			ra_rotate_a(ps);
			j--;
		}
	}
	return (0);
}
