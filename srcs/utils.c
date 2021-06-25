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
	if (ut->map)
	{
		while (i < ut->map_size)
		{
			free(ut->map[i]);
			i++;
		}
		free(ut->map);
	}
}