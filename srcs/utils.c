/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:45:20 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:45:22 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_ut *ut)
{
	int	j;

	j = 0;
	while (j < ut->map_size)
	{
		ft_putstr_fd(ut->map[j], 0);
		ft_putstr_fd("\n", 0);
		j++;
	}
}

void	ft_free(t_ut *ut)
{
	int	i;

	i = 0;
	if (ut->map_exist == 1)
	{
		while (i < ut->map_size)
		{
			free(ut->map[i]);
			i++;
		}
		free(ut->map);
	}
}

int	is_map(t_ut *ut)
{
	int	i;
	int	j;

	j = 0;
	while (j < ut->map_size)
	{
		i = 0;
		while (ut->map[j][i])
		{
			if (ut->map[j][i] != '0' && ut->map[j][i] != '1'
				&& ut->map[j][i] != 'C' && ut->map[j][i] != 'E'
				&& ut->map[j][i] != 'P')
			{	
				ft_putstr_fd("Error\nwrong char in map", 0);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

void	move_with_collect_up(t_ut *ut, int key)
{
	if (key == UP && ut->map[ut->sp.y + 1][ut->sp.x] != '1')
	{
		if (ut->map[ut->sp.y + 1][ut->sp.x] == 'E')
			ft_exit(ut);
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y + 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
	if (key == DOWN && ut->map[ut->sp.y - 1][ut->sp.x] != '1')
	{
		if (ut->map[ut->sp.y - 1][ut->sp.x] == 'E')
			ft_exit(ut);
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y - 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
}

void	deal_key_up(int key, t_ut *ut)
{
	if (key == UP && ut->map[ut->sp.y + 1][ut->sp.x] != '1'
		&& ut->map[ut->sp.y + 1][ut->sp.x] != 'E')
	{
		if (ut->map[ut->sp.y + 1][ut->sp.x] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y + 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
	if (key == DOWN && ut->map[ut->sp.y - 1][ut->sp.x] != '1'
		&& ut->map[ut->sp.y - 1][ut->sp.x] != 'E')
	{
		if (ut->map[ut->sp.y - 1][ut->sp.x] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y - 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
	ft_escape(ut, key);
}
