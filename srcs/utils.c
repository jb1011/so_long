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
			if (ut->map[j][i] != '0' && ut->map[j][i] != '1' && ut->map[j][i] != 'C' && ut->map[j][i] != 'E' && ut->map[j][i] != 'P')
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