/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:59:27 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:59:29 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_spawn(t_ut *ut, int j)
{
	int	i;

	i = 0;
	while (ut->map[j][i])
	{
		if (ut->map[j][i] == 'P')
			ut->is_spawn++;
		if (ut->map[j][i] == 'E')
			ut->is_exit++;
		if (ut->map[j][i] == 'C')
			ut->collect++;
		i++;
	}
}
