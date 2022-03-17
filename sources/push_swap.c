/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/17 15:11:45 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_game(t_push_swap *ps)
{
	if (is_stack_sorted(ps) == 0)
	{
		if (ps->size < 3)
			sa_swap_a(ps);
		else if (ps->size < 4)
			sort_stack_min_3(ps);
		else if (ps->size > 3 && ps->size < 6)
			sort_stack_min_5(ps);
		else
			sort_stack_max_500(ps);
	}
	free_push_swap(ps);
	return (0);
}

int	push_swap(char *argv[], t_push_swap *ps, int argc)
{
	if (check_num_argv(argv) == 0)
	{
		if (check_rep_num_argv(argv, argc, ps) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			free_push_swap(ps);
			return (1);
		}
		init_game(ps);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_push_swap	ps;

	if (argc > 1)
		push_swap(argv, &ps, argc);
	else
		return (1);
	return (0);
}
