/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:16:25 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 10:49:48 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_ra(t_stack *a)
{
	int	tmp;

	tmp = a->array[0];
	move_up(a);
	a->array[a->len - 1] = tmp;
}

void	checker_rb(t_stack *b)
{
	int	tmp;

	if (b->len > 1)
	{
		tmp = b->array[0];
		move_up(b);
		b->array[b->len - 1] = tmp;
	}
}

void	checker_rr(t_stack *a, t_stack *b)
{
	checker_ra(a);
	checker_ra(b);
}

void	checker_rra(t_stack *a)
{
	int	tmp;

	tmp = a->array[a->len - 1];
	move_down(a);
	a->array[0] = tmp;
}

void	checker_rrb(t_stack *b)
{
	int	tmp;

	tmp = b->array[b->len - 1];
	move_down(b);
	b->array[0] = tmp;
}
