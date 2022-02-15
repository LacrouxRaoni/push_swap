/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/15 00:17:40 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_stack_max_100(t_push_swap * ps)
{
	
	while(ps->len_a > 0)
		pb_push_b(ps);
	while (1)
	{
		find_max_min_stack_b(ps);
		while (1)
		{
			if (ps->stack_b[0] == ps->max)
			{
				pa_push_a(ps);
				break ;
			}
			else
				rb_rotate_b(ps);
		}
		while (1)
		{
			if (ps->stack_b[0] == ps->min)
			{
				pa_push_a(ps);
				ra_rotate_a(ps);
				break ;
			}
			else
				rb_rotate_b(ps);
		}
		if (ps->len_b == 0)
			break ;
	}
	while (is_stack_sorted(ps) == 0)
		ra_rotate_a(ps);
}

static int	init_game(t_push_swap *ps)
{
	if (is_stack_sorted(ps) == 0)
	{
		if (ps->top < 3)
			sa_swap_a(ps);
		else if (ps->top < 4)
			sort_stack_min_3(ps);
		else if (ps->top > 3 && ps->top < 6)
			sort_stack_min_5(ps);
		else 
			sort_stack_max_100(ps);
		if (is_stack_sorted(ps) == 1)
		{
			printf ("%d\n", ps->stack_a[0]);
			printf ("%d\n", ps->stack_a[1]);
			printf ("%d\n", ps->stack_a[2]);
			printf ("%d\n", ps->stack_a[3]);
			printf ("%d\n", ps->stack_a[4]);
			printf ("%d\n", ps->stack_a[5]);
		}
	}
	/*int i;
	int j;

	i = 0;
	while (is_stack_sorted(ps) == 0)
	{
		if (ps->stack_a[0] < ps->stack_a[1])
		{
			j = 1;
			while (j < ps->len_a)
			{
				if (ps->stack_a[0] > ps->stack_a[j])	
				{		
					if (j < ps->top / 2)
						ra_rotate_a(ps);					
					else
						rra_rev_a(ps);
				}
				j++;
			}
			pb_push_b(ps);
		}
		else
			sa_swap_a(ps);
		i++;
		if (ps->len_a == 1)
			while (i > 0)
			{
				pa_push_a(ps);
				i--;
			}
	}*/
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
