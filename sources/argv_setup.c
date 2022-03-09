/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:25 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/08 19:49:50 by rruiz-la         ###   ########.fr       */
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

int	check_rep_num_argv(char **argv, int len_argv, t_push_swap *ps)
{
	int	i;
	int	j;

	malloc_stack(ps, len_argv - 1);
	ps->size = len_argv - 1;
	ps->len_a = len_argv - 1;
	ps->len_b = 0;
	ps->pos_min_b = 0;
	ps->b = 0;
	i = 0;
	j = -1;
	while (argv[++i] != NULL)
	{
		if (ft_atoi(argv[i]) <= INT_MIN || ft_atoi(argv[i]) >= INT_MAX)
			return (1);
		else
			ps->stack_a[++j] = ft_atoi(argv[i]);
	}
	i = 0;
	while (i < len_argv - 1)
	{
		j = i + 1;
		while (j < len_argv - 1)
		{
			if ((ps->stack_a[i] - ps->stack_a[j]) == 0)
			{
				free_push_swap(ps);
				return (1);
			}
			j++;
		}
		i++;
	}
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
