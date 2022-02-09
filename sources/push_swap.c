/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/08 18:28:50 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	verify_list(t_push_swap *ps)
{
	int	i;
	int	j;

	i = 0;
	while ( i < ps->top - 1)
	{
		j = i + 1;
		while (j < ps->top)
		{
			if (ps->stack_a[i] > ps->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	init_game(t_push_swap *ps)
{
	
	if (verify_list(ps) == 1)
		return (1);

	sa_swap_a(ps);
	sb_swap_b(ps);
	ss_sa_n_sb(ps);
	pa_push_a(ps);
	pb_push_b(ps);
	ra_rotate_a(ps);
	rb_rotate_b(ps);
	rr_ra_rb(ps);
	rra_rev_a(ps);
	rrb_rev_b(ps);
	rrr_a_b (ps);
	return (0);
}

int	push_swap(char *argv[], t_push_swap *ps, int argc)
{
	if (check_num_argv(argv) == 0)
	{
		if (check_rep_num_argv(argv, argc, ps) == 1)
		{
			ft_putstr_fd("Error\nsome arguments are duplicated", 1);
			return (1);
		}
		init_game(ps);
	}
	else
	{
		ft_putstr_fd("Error\nsome arguments aren't integers", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_push_swap	ps;

	if (argc > 1)
	{
		push_swap(argv, &ps, argc);
		free_push_swap(&ps);
	}	
	else
		return (1);
	return (0);
}
