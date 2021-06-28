#include "../includes/so_long.h"

int	deal_key(int key, t_ut *ut)
{
	find_spawn(ut);
	move_with_collect(ut, key);
	if (key == RIGHT && ut->map[ut->sp.y][ut->sp.x + 1] != '1' && ut->map[ut->sp.y][ut->sp.x + 1] != 'E')
	{
		if (ut->map[ut->sp.y][ut->sp.x + 1] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y][ut->sp.x + 1] = 'P';
		display_move(ut);
		display_text(ut);
	}
	if (key == LEFT && ut->map[ut->sp.y][ut->sp.x - 1] != '1' && ut->map[ut->sp.y][ut->sp.x - 1] != 'E')
	{
		if (ut->map[ut->sp.y][ut->sp.x - 1] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y][ut->sp.x - 1] = 'P';
		display_move(ut);
		display_text(ut);
	}
	if (key == UP && ut->map[ut->sp.y + 1][ut->sp.x] != '1' && ut->map[ut->sp.y + 1][ut->sp.x] != 'E')
	{
		if (ut->map[ut->sp.y + 1][ut->sp.x] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y + 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
	if (key == DOWN && ut->map[ut->sp.y - 1][ut->sp.x] != '1' && ut->map[ut->sp.y - 1][ut->sp.x] != 'E')
	{
		if (ut->map[ut->sp.y - 1][ut->sp.x] == 'C')
			ut->take++;
		ut->map[ut->sp.y][ut->sp.x] = '0';
		ut->map[ut->sp.y - 1][ut->sp.x] = 'P';
		display_move(ut);
		display_text(ut);
	}
	ft_escape(ut, key);
	return (0);
}

void	move_with_collect(t_ut *ut, int key)
{
	if (ut->take == ut->collect)
	{
		if (key == RIGHT && ut->map[ut->sp.y][ut->sp.x + 1] != '1')
		{
			if (ut->map[ut->sp.y][ut->sp.x + 1] == 'E')
				ft_exit(ut);
			ut->map[ut->sp.y][ut->sp.x] = '0';
			ut->map[ut->sp.y][ut->sp.x + 1] = 'P';
			display_move(ut);
			display_text(ut);
		}
		if (key == LEFT && ut->map[ut->sp.y][ut->sp.x - 1] != '1')
		{
			if (ut->map[ut->sp.y][ut->sp.x - 1] == 'E')
				ft_exit(ut);
			ut->map[ut->sp.y][ut->sp.x] = '0';
			ut->map[ut->sp.y][ut->sp.x - 1] = 'P';
			display_move(ut);
			display_text(ut);
		}
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
}

void find_spawn(t_ut *ut)
{
	int	i;
	int	j;

	j = 0;
	while (j < ut->map_size)
	{
		i = 0;
		while (i < ut->len)
		{
			if (ut->map[j][i] == 'P')
			{
				ut->sp.x = i;
				ut->sp.y = j;
			}
			i++;
		}
		j++;
	}
}

void	display_move(t_ut *ut)
{
	ut->count++;
	ft_putnbr_fd(ut->count, 0);
	ft_putstr_fd("\n", 0);
}

void	ft_escape(t_ut *ut, int key)
{
	if (key == ESCAPE)
	{
		ft_exit(ut);
	}
}