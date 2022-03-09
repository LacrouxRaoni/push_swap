/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:31:07 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/03/05 18:48:47 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_push_swap *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->size)
	{
		j = i + 1;
		while (j < ps->size)
		{
			if (ps->stack_a[i] > ps->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
