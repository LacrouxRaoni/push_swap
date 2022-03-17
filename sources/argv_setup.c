/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:25 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/17 15:45:03 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	malloc_stack(t_push_swap *ps, int len)
{
	ps->stack_a = (int *)malloc(sizeof(int) * len);
	if (!ps->stack_a)
		exit(1);
	ps->stack_b = (int *)malloc(sizeof(int) * len);
	if (!ps->stack_b)
		exit(1);
}

static int	init_var(t_push_swap *ps, int len)
{
	ps->size = len - 1;
	ps->len_a = len - 1;
	ps->len_b = 0;
	ps->pos_min_b = 0;
	ps->pos_max_b = 0;
	ps->pos_min_a = 0;
	ps->pos_max_a = 0;
	ps->b = 0;
}

static int	check_rep_num(t_push_swap *ps, int len_argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_argv - 1)
	{
		j = i + 1;
		while (j < len_argv - 1)
		{
			if ((ps->stack_a[i] - ps->stack_a[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_rep_num_argv(char **argv, int len_argv, t_push_swap *ps)
{
	int	i;
	int	j;

	malloc_stack(ps, len_argv - 1);
	init_var(ps, len_argv);
	i = 0;
	j = -1;
	while (argv[++i] != NULL)
	{
		if (long_atoi(argv[i]) <= INT_MIN || long_atoi(argv[i]) >= INT_MAX)
			return (1);
		else
			ps->stack_a[++j] = long_atoi(argv[i]);
	}
	if (check_rep_num(ps, len_argv) == 1)
		return (1);
	return (0);
}

int	check_num_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				j++;
			else
				return (-1);
		}
	}
	return (0);
}
