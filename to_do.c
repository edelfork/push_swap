/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:22:08 by gimartin          #+#    #+#             */
/*   Updated: 2022/03/25 09:44:38 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_best(t_stack *a, int val)
{
	int	i;

	i = 0;
	while (i < a->best_len)
	{
		if (val < a->best[i])
			return (0);
		if (val == a->best[i])
			return (1);
		i++;
	}
	return (0);
}

int	to_do(t_stack *b, int min, int max)
{
	int	i;

	i = 0;
	while (i < b->len)
	{
		if (b->array[i] >= min && b->array[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

int	to_do_a(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->array[i] >= min && a->array[i] <= max
			&& !in_best(a, a->array[i]))
			return (1);
		i++;
	}
	return (0);
}
