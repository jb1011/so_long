#include "../includes/so_long.h"

void	window_init(t_ut *ut)
{
	ut->count = 0;
	ut->mlx_ptr = mlx_init();
	ut->win_ptr = mlx_new_window(ut->mlx_ptr, 500, 500, "So_long");
	get_text(ut);
	display_text(ut);
	mlx_hook(ut->win_ptr, 2, 1L << 0, deal_key, ut);
	mlx_hook(ut->win_ptr, 33, 1L << 17, ft_exit, ut);
	mlx_loop(ut->mlx_ptr);
}

int	ft_exit(t_ut *ut)
{
	ft_free(ut);
	ft_destroy_text(ut);
	mlx_destroy_window(ut->mlx_ptr, ut->win_ptr);
	exit(0);
}