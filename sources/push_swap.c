/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:34:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/08 21:05:50 by rruiz-la         ###   ########.fr       */
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

static int sort_stack_b(t_push_swap *ps)
{
	int	min_to_botton;
	int	max_to_botton;
	int	j;

	j = 0;
	while (ps->len_b > 0)
	{	
		min_to_botton = 0;
		max_to_botton = 0;
		find_max_min_stack_b(ps);
		min_to_botton = ps->len_b - ps->pos_min_b;
		max_to_botton = ps->len_b - ps->pos_max_b;
		if (ps->pos_min_b < ps->pos_max_b && ps->pos_min_b < min_to_botton && ps->pos_min_b < max_to_botton)
			push_min_to_a(ps);
		else if (min_to_botton < ps->pos_min_b && min_to_botton < ps->pos_max_b && min_to_botton < max_to_botton)
			push_min_to_a(ps);
		else if (ps->pos_max_b < ps->pos_min_b && ps->pos_max_b < min_to_botton && ps->pos_max_b < max_to_botton)
		{
			push_max_to_a(ps);
			j++;
		}
		else if (max_to_botton < ps->pos_min_b && max_to_botton < ps->pos_max_b && max_to_botton < min_to_botton)
		{
			push_max_to_a(ps);
			j++;
		}
		else
			push_min_to_a(ps);
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



static void sort_stack_max_100(t_push_swap *ps)
{
	int	*pos;
	int i;
	int	top_stack;
	int first_bucket;
	
	pos = malloc(sizeof(int *) * ps->size);
	define_position_stack_a(ps, pos);
	i = -1;
	while (++i < ps->len_a)
		ps->stack_a[i] = pos[i];


	


		while (ps->len_b < ps->size / 2)
		{
			if (ps->stack_a[0] < ps->size / 2)
			{
				pb_push_b(ps);
					
			}
			else
			{
				if (ps->stack_a[0] > ps->size / 2 && ps->stack_b[0] < ps->size / 4)
					rr_ra_rb(ps);
				else
					ra_rotate_a(ps);
			}
		}








		top_stack = ps->stack_a[0];
		while (ps-> len_b > 31)
		{
			if (ps->stack_b[0] > 30)
			{
				pa_push_a(ps);
			}
			else
				rb_rotate_b(ps);
		}
		if (ps->len_b <= 31)
			sort_stack_b(ps);
		if (ps->len_b == 0)
			first_bucket = ps->stack_a[ps->len_a - 1];
		while (ps->stack_a[0] != top_stack)
		{
			if (ps->stack_a[0] == first_bucket + 1)
				ra_rotate_a(ps);
			else
				pb_push_b(ps);
		}
		if (ps->len_b <=31)
			sort_stack_b(ps);
		else
		{
			if (ps->stack_a[0] > ps->size / 2 && ps->stack_b[0] < ps->size / 4)
				rr_ra_rb(ps);
			else
				ra_rotate_a(ps);
		}






		i = ps->stack_a[ps->len_a - 1];
		while (ps->stack_a[0] != 0)
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
		while (ps->max_b > 75)
		{
			if(ps->stack_b[0] == i + 1)
			{
				pa_push_a(ps);
				ra_rotate_a(ps);
				i++;
			}
			else if (ps->stack_b[0] > 75)
			{
				pa_push_a(ps);
			}
			else
				rb_rotate_b(ps);
			find_max_min_stack_b(ps);
		}
		sort_stack_b(ps);
		while (ps->stack_a[0] != 0)
		{
			if (ps->stack_a[0] == i + 1)
				ra_rotate_a(ps);
			else
				pb_push_b(ps);
		}
		sort_stack_b(ps);
	free (pos);
	free_push_swap(ps);
}

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
			ft_putstr_fd("Error\n", 1);
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
	{
		push_swap(argv, &ps, argc);
	}	
	else
		return (1);
	return (0);
}
