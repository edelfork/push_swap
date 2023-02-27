/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:50:32 by gimartin          #+#    #+#             */
/*   Updated: 2022/03/27 18:09:28 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_char(char *argv)
{
	int	i;

	i = 0;
	if (argv == 0 || argv[i] == 0)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
