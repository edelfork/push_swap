/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:46:46 by gimartin          #+#    #+#             */
/*   Updated: 2022/03/25 12:17:21 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_med(t_stack *a, int min, int max)
{
	int	i;
	int	den;
	int	sum;

	i = 0;
	den = 0;
	sum = 0;
	while (i < a->len)
	{
		if (a->array[i] >= min && a->array[i] < max)
		{
			sum += a->array[i];
			den++;
		}
		i++;
	}
	if (den != 0)
		return (sum / den);
	else
		return (a->min);
}

int	get_half(t_stack *a, int min, int max)
{
	int	med;
	int	i;
	int	diff;
	int	ret;

	if (max <= min)
		return (0);
	med = get_med(a, min, max);
	i = 0;
	ret = 0;
	while (a->array[i] < min || a->array[i] > max)
		i++;
	diff = ft_abs(med - a->array[i]);
	i = 0;
	while (i < a->len)
	{
		if (a->array[i] >= min && a->array[i] < max
			&& ft_abs(med - a->array[i]) < diff)
		{
			diff = ft_abs(med - a->array[i]);
			ret = a->array[i];
		}
		i++;
	}
	return (ret);
}
