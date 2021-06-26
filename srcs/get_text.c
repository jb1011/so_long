#include "../includes/so_long.h"

int	get_text(t_ut *ut)
{
	ut->text[0].img = mlx_xpm_file_to_image(ut->mlx_ptr, "textures/floor.xpm", &(ut->text[0].width), &(ut->text[0].height));
	if (!ut->text[0].img)
	{
		ft_destroy_text(ut);
		return (0);
	}
	ut->text[0].addr = (int *)mlx_get_data_addr(ut->text[0].img, &ut->text[0].bpp, &ut->text[0].line_height, &ut->text[0].endian);
	
	ut->text[1].img = mlx_xpm_file_to_image(ut->mlx_ptr, "textures/wall.xpm", &(ut->text[1].width), &(ut->text[1].height));
	if (!ut->text[1].img)
	{
		ft_destroy_text(ut);
		return (0);
	}
	ut->text[1].addr = (int *)mlx_get_data_addr(ut->text[1].img, &ut->text[1].bpp, &ut->text[1].line_height, &ut->text[1].endian);

	ut->text[2].img = mlx_xpm_file_to_image(ut->mlx_ptr, "textures/player.xpm", &(ut->text[2].width), &(ut->text[2].height));
	if (!ut->text[2].img)
	{
		ft_destroy_text(ut);
		return (0);
	}
	ut->text[2].addr = (int *)mlx_get_data_addr(ut->text[2].img, &ut->text[2].bpp, &ut->text[2].line_height, &ut->text[2].endian);
	
	ut->text[3].img = mlx_xpm_file_to_image(ut->mlx_ptr, "textures/brick.xpm", &(ut->text[3].width), &(ut->text[3].height));
	if (!ut->text[3].img)
	{
		ft_destroy_text(ut);
		return (0);
	}
	ut->text[3].addr = (int *)mlx_get_data_addr(ut->text[3].img, &ut->text[3].bpp, &ut->text[3].line_height, &ut->text[3].endian);

	ut->text[4].img = mlx_xpm_file_to_image(ut->mlx_ptr, "textures/door.xpm", &(ut->text[4].width), &(ut->text[4].height));
	if (!ut->text[4].img)
	{
		ft_destroy_text(ut);
		return (0);
	}
	ut->text[4].addr = (int *)mlx_get_data_addr(ut->text[4].img, &ut->text[4].bpp, &ut->text[4].line_height, &ut->text[4].endian);
	return (1);
}

void	ft_destroy_text(t_ut *ut)
{
	if (ut->text[0].img)
		mlx_destroy_image(ut->mlx_ptr, ut->text[0].img);
	if (ut->text[1].img)
		mlx_destroy_image(ut->mlx_ptr, ut->text[1].img);
	if (ut->text[2].img)
		mlx_destroy_image(ut->mlx_ptr, ut->text[2].img);
	if (ut->text[3].img)
		mlx_destroy_image(ut->mlx_ptr, ut->text[3].img);
	mlx_destroy_display(ut->mlx_ptr);
	exit(0);
}