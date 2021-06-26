#include "../includes/so_long.h"

void	window_init(t_ut *ut)
{
	ut->mlx_ptr = mlx_init();
	ut->win_ptr = mlx_new_window(ut->mlx_ptr, 500, 500, "So_long");
	// mlx_hook(ut->win_ptr, 33, 1L << 17,)
	get_text(ut);
	display_text(ut);
	mlx_loop(ut->mlx_ptr);
}