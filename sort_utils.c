/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:37:35 by gimartin          #+#    #+#             */
/*   Updated: 2022/03/25 15:22:33 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->max == a->array[2])
		sa(a, 1);
	else if (a->max == a->array[0] && a->array[1] > a->array[2])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->max == a->array[0] && a->array[1] < a->array[2])
		ra(a, 1);
	else if (a->min == a->array[0] && a->array[1] > a->array[2])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->max == a->array[1])
		rra(a, 1);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		find_min(a);
		while (find_ind(a, a->min) < a->len / 2 && find_ind(a, a->min))
			ra(a, 1);
		while (find_ind(a, a->min) >= a->len / 2 && find_ind(a, a->min))
			rra(a, 1);
		pb(a, b);
	}
	find_max_min(a);
	sort_3(a);
	find_max_min(a);
	pa(a, b);
	pa(a, b);
	if (!ordered(a))
		sa(a, 1);
}

void	fill_range(t_stack *a, t_stack *b, int min, int flag)
{
	int	moves;

	if (flag && !a->len)
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
		find_max_min(a);
		sort_3(a);
	}
	find_max_min(a);
	while (to_do(b, min, b->max + 1))
	{
		moves = decide(a, b);
		find_place_and_insert(a, b, moves);
		find_max_min(a);
		find_max_min(b);
	}
}

void	range(t_stack *a, t_stack *b, int min, int max)
{
	while (to_do_a(a, min, max))
	{
		if (a->array[0] >= min && a->array[0] <= max
			&& !in_best(a, a->array[0]))
			pb(a, b);
		else
			ra(a, 1);
		find_max_min(b);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	middle_half;
	int	front_half;
	int	tail_half;

	get_lis(a->array, a->len, a);
	find_max_min(a);
	middle_half = get_half(a, a->min, a->max);
	front_half = get_half(a, a->min, middle_half);
	tail_half = get_half(a, middle_half, a->max);
	range(a, b, tail_half, a->max);
	range(a, b, middle_half, a->max);
	range(a, b, front_half, a->max);
	range(a, b, a->min, a->max);
	fill_range(a, b, a->min, 0);
	find_max_min(a);
	while (find_ind(a, a->min) >= a->len / 2 && find_ind(a, a->min))
		rra(a, 1);
	while (find_ind(a, a->min) < a->len / 2 && find_ind(a, a->min))
		ra(a, 1);
}
