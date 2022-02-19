/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/02/18 23:24:32 by rruiz-la         ###   ########.fr       */
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
	while(ps->len_b > 0)
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
			{
				rb_rotate_b(ps);
			}
			else
				rrb_rev_b(ps);
		}
	}
	return (0);
}

static int *define_position_stack_a(t_push_swap *ps, int *pos)
{
	int i;
	int	j;
	int k;

	if (ps->len_a == 0)
		return (0);
	i = 0;
	while(i < ps->len_a)
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

static int sort_stack_b(t_push_swap *ps)
{
	int j;

	j = 0;
	while (ps->len_b > 0)
	{	
		find_max_min_stack_b(ps);
		if (push_max_to_a(ps) == 0)
			j++;
		push_min_to_a(ps);
		if (ps->len_b == 0)
		{
			while (j > 0)
			{
				ra_rotate_a(ps);
				j--;
			}
			
		}
		
	}
	return (0);
}

static void sort_stack_max_100(t_push_swap *ps)
{
	int	*pos;
	int i;
	int	r;

	pos = malloc(sizeof(int *) * ps->top);
	define_position_stack_a(ps, pos);
	i = -1;
	while (++i < ps->len_a)
		ps->stack_a[i] = pos[i];
	i = 0;
	r = 50;
	while(1)
	{
		if (r == 50)
		{
			while (i < ps->top / 2)
			{
				find_max_min_stack_a(ps);
				if (ps->stack_a[0] > (ps->top / 2) - 1 && ps->stack_a[0] < ps->top)
				{
					pb_push_b(ps);
					rb_rotate_b(ps);
					i++;
				}				
				else
				{
					if (ps->pos_max_a < ps->len_a / 2 || ps->pos_max_a - 1 < ps->len_a / 2)
						ra_rotate_a(ps);
					else
						rra_rev_a(ps);
				}
				
			}
		}
		if (r == 100)
		{
			while (ps->len_a > 0)
			{
				find_max_min_stack_a(ps);
				if (ps->stack_a[0] == ps->min_a)
				{
					pb_push_b(ps);
				}				
				else
				{
					if (ps->pos_min_a < ps->len_a / 2)
					{
						ra_rotate_a(ps);
					}
					else
						rra_rev_a(ps);
				}
			}
			while (i > 0)
			{
				pa_push_a(ps);
				i--;
			}
		}
		if (r == 100)
		{
			sort_stack_b(ps);
			break ;
		}
		r = r + 50;

	}
	free (pos);
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
	}
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
