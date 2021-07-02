/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:46:20 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:46:26 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_check_side_wall(t_ut *ut)
{
	int	i;
	int	last;

	i = 0;
	while (i < ut->map_size)
	{
		if (ut->map[i][0] != '1')
		{
			ft_putstr_fd("Error\nproblem with left wall", 0);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < ut->map_size)
	{
		last = ft_strlen(ut->map[i]) - 1;
		if (ut->map[i][last] != '1')
		{
			ft_putstr_fd("Error\nproblem with right wall", 0);
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_check_spawn(t_ut *ut)
{
	int	j;

	j = 0;
	ut->is_spawn = 0;
	ut->collect = 0;
	ut->is_exit = 0;
	ut->take = 0;
	while (j < ut->map_size)
	{
		move_spawn(ut, j);
		j++;
	}
	if (ut->is_exit != 1 || ut->is_spawn != 1 || ut->collect == 0)
	{
		ft_putstr_fd("Error\nProblem with spawn, collectible or exit", 0);
		return (0);
	}
	return (1);
}

int	map_check_rect(t_ut *ut)
{
	int	i;
	int	last;
	int	curr;

	i = 1;
	while (i < ut->map_size)
	{
		curr = ft_strlen(ut->map[i]);
		last = ft_strlen(ut->map[i - 1]);
		if (last != curr)
		{
			ft_putstr_fd("Error\nmap is not rectangle", 0);
			return (0);
		}
		i++;
	}
	return (1);
}
