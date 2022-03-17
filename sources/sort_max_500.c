/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:55:02 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/15 16:35:58 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*define_position_stack_a(t_push_swap *ps, int *pos)
{
	int	i;
	int	j;
	int	k;

	if (ps->len_a == 0)
		return (0);
	i = 0;
	while (i < ps->len_a)
	{
		j = 0;
		k = 0;
		pos[i] = 0;
		while (j < ps->len_a)
		{
			if (ps->stack_a[i] > ps->stack_a[j])
			{
				k++;
				pos[i] = k;
			}
			j++;
		}	
		i++;
	}
	return (pos);
}

static void	verify_stack_a_pos(t_push_swap *ps)
{
	int	i;
	int	*pos;

	pos = malloc(sizeof(int *) * ps->size);
	define_position_stack_a(ps, pos);
	i = -1;
	while (++i < ps->len_a)
		ps->stack_a[i] = pos[i];
	free (pos);
}

static void	send_half_min_stack_b(t_push_swap *ps)
{
	while (ps->len_b < ps->size / 2)
	{
		if (ps->stack_a[0] < ps->size / 2)
			pb_push_b(ps);
		else
		{
			if (ps->stack_a[0] > ps->size / 2 && ps->stack_b[0] < ps->size / 4)
				rr_ra_rb(ps);
			else
				ra_rotate_a(ps);
		}
	}
}

static void	sort_rest_num(t_push_swap *ps, int cut_point_one)
{
	int	i;

	i = 0;
	if (ps->len_b == 0)
		i = ps->stack_a[ps->len_a - 1];
	while (ps->stack_a[0] != cut_point_one)
	{
		if (ps->stack_a[0] == i + 1)
		{
			ra_rotate_a(ps);
			i++;
		}
		else
			pb_push_b(ps);
	}
	find_max_min_stack_b(ps);
	while (ps->len_b > 31)
	{
		if (ps->stack_b[0] > ps->min_b + 30)
			pa_push_a(ps);
		else
			rb_rotate_b(ps);
	}
	sort_stack_b(ps);
}

void	sort_stack_max_500(t_push_swap *ps)
{
	int	i;
	int	cut_point_one;
	int	cut_half;

	verify_stack_a_pos(ps);
	send_half_min_stack_b(ps);
	find_max_min_stack_b(ps);
	cut_half = ps->max_b;
	cut_point_one = ps->stack_a[0];
	while (ps-> len_b > 31)
	{
		if (ps->stack_b[0] > 30)
			pa_push_a(ps);
		else
			rb_rotate_b(ps);
	}
	if (ps->len_b <= 31)
		sort_stack_b(ps);
	while (is_stack_sorted(ps) == 0)
	{
		sort_rest_num(ps, cut_point_one);
		if (ps->stack_a[ps->len_a - 1] == cut_half)
			cut_point_one = 0;
	}
}
