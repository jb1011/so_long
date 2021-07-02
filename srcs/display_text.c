/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:45:41 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:45:43 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_text(t_ut *ut)
{
	int	i;
	int	x;
	int	y;

	ut->j = 0;
	y = 0;
	while (ut->j < ut->map_size)
	{
		i = 0;
		x = 0;
		while (i < ut->len)
		{
			display_text2(ut, i, x, y);
			i++;
			x += 32;
		}
		ut->j++;
		y += 32;
	}
}

void	display_text2(t_ut *ut, int i, int x, int y)
{
	if (ut->map[ut->j][i] == '0')
	{
		mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr,
			ut->text[0].img, x, y);
	}
	if (ut->map[ut->j][i] == '1')
	{
		mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr,
			ut->text[1].img, x, y);
	}
	if (ut->map[ut->j][i] == 'P')
	{
		mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr,
			ut->text[2].img, x, y);
	}
	if (ut->map[ut->j][i] == 'C')
	{
		mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr,
			ut->text[3].img, x, y);
	}
	if (ut->map[ut->j][i] == 'E')
	{
		mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr,
			ut->text[4].img, x, y);
	}
}
