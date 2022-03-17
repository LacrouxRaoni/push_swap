/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:09:48 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/15 19:19:11 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_min_3(t_push_swap *ps)
{
	/*find_max_min_stack_a(ps);
	if(ps->stack_a[0] == ps->max_a)
	{
		if (ps->stack_a[1] == ps->min_a)
			ra_rotate_a(ps);
		else
		{
			ra_rotate_a(ps);
			sa_swap_a(ps);
		}
	}
	else if (ps->stack_a[1] == ps->max_a)
	{
		if (ps->stack_a[2] == ps->min_a)
			rra_rev_a(ps);
		else
		{
			sa_swap_a(ps);
			ra_rotate_a(ps);
		}
	}
	else
		sa_swap_a(ps);
	*/
	if (is_stack_sorted(ps) == 0)
	{
		if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[0] < ps->stack_a[2])
			sa_swap_a(ps);
		else if (ps->stack_a[0] > ps->stack_a[1]
			&& ps->stack_a[0] > ps->stack_a[2])
		{
			if (ps->stack_a[1] > ps->stack_a[2])
			{
				sa_swap_a(ps);
				rra_rev_a(ps);
			}
			else
				ra_rotate_a(ps);
		}
		else if (ps->stack_a[0] < ps->stack_a[1]
			&& ps->stack_a[0] < ps->stack_a[2])
		{
			sa_swap_a(ps);
			ra_rotate_a(ps);
		}
		else if (ps->stack_a[0] < ps->stack_a[1]
			&& ps->stack_a[0] > ps->stack_a[2])
			rra_rev_a(ps);
	}
}	

static int	validate_pb(t_push_swap *ps, int i)
{
	while (++i < ps->size)
	{
		if (ps->size < 5)
		{
			if (ps->stack_a[0] == ps->min_a)
			{
				pb_push_b(ps);
				return (0);
			}
			else
				ra_rotate_a(ps);
		}
		else
		{
			if (ps->stack_a[0] == ps->max_a || ps->stack_a[0] == ps->min_a)
			{	
				pb_push_b(ps);
				if (ps->len_b == 2)
					return (0);
			}
			else
				ra_rotate_a(ps);
		}
	}	
}

void	sort_stack_min_5(t_push_swap *ps)
{
	int	i;

	i = -1;
	find_max_min_stack_a(ps);
	validate_pb(ps, i);
	if (ps->len_b == 2 && ps->stack_b[0] < ps->stack_b[1])
		sb_swap_b(ps);
	sort_stack_min_3(ps);
	pa_push_a(ps);
	if (ps->len_b > 0)
		ra_rotate_a(ps);
	pa_push_a(ps);
}
