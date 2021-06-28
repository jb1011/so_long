#include "../includes/so_long.h"

void	window_init(t_ut *ut)
{
	
	ut->mlx_ptr = mlx_init();
	mlx_get_screen_size(ut->mlx_ptr, &ut->sizex, &ut->sizey);
	if (ft_get_screen_res(ut) == 1)
	{
		get_text(ut);
		display_text(ut);
		mlx_hook(ut->win_ptr, 2, 1L << 0, deal_key, ut);
		mlx_hook(ut->win_ptr, 33, 1L << 17, ft_exit, ut);
		mlx_loop(ut->mlx_ptr);
	}
}

int	ft_exit(t_ut *ut)
{
	ft_free(ut);
	ft_destroy_text(ut);
	mlx_destroy_window(ut->mlx_ptr, ut->win_ptr);
	exit(0);
}

int	ft_get_screen_res(t_ut *ut)
{
	int x;
	int y;

	ut->count = 0;
	ut->len = ft_strlen(ut->map[0]);
	x = ut->len * 32;
	y = ut->map_size * 32;
	if (x > ut->sizex)
	{
		ft_putstr_fd("Error\nmap is too big for screen", 0);
		return (0);
	}
	if (y > ut->sizey)
	{
		ft_putstr_fd("Error\nmap is too big for screen", 0);
		return (0);
	}
	ut->win_ptr = mlx_new_window(ut->mlx_ptr, x, y, "So_long");
	return (1);
}
