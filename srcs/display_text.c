#include "../includes/so_long.h"

void	display_text(t_ut *ut)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	ut->len = ft_strlen(ut->map[0]);
	while (j < ut->map_size)
	{
		i = 0;
		x = 0;
		while (i < ut->len)
		{
			if (ut->map[j][i] == '0')
			{
				mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr, ut->text[0].img, x, y);
			}
			if (ut->map[j][i] == '1')
			{
				mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr, ut->text[1].img, x, y);
			}
			if (ut->map[j][i] == 'P')
			{
				mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr, ut->text[2].img, x, y);
			}
			if (ut->map[j][i] == 'C')
			{
				mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr, ut->text[3].img, x, y);
			}
			if (ut->map[j][i] == 'E')
			{
				mlx_put_image_to_window(ut->mlx_ptr, ut->win_ptr, ut->text[4].img, x, y);
			}
			i++;
			x += 32;
		}
		j++;
		y += 32;

	}
}