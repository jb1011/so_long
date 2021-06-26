#include "../includes/so_long.h"

void	get_map_size(t_ut *ut)
{
	int		fd;
	int		ret;
	char	*str;
	int		i;

	fd = open(ut->map_name, O_RDONLY);
	ut->map_exist = 0;
	if (fd == -1)
	{
		ft_putstr_fd("Error\nproblem with file", 0);
		return ;
	}
	i = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		i++;
		free(str);
	}
	free(str);
	i++;
	ut->map_size = i;
	map_malloc(ut);
}

void	map_malloc(t_ut *ut)
{
	int		fd;
	int		ret;
	char	*str;
	int		i;

	i = 0;
	fd = open(ut->map_name, O_RDONLY);
	ut->map = malloc(sizeof(char *) * (ut->map_size));
	ut->map_exist = 1;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		ut->map[i] = ft_strdup(str);
		i++;
		free(str);
	}
	ut->map[i] = ft_strdup(str);
	free(str);
	if (map_check(ut) == 1)
		window_init(ut);
}

int	map_check(t_ut *ut)
{
	if (!is_map(ut) || !map_check_wall(ut) || !map_check_side_wall(ut) ||
		!map_check_spawn(ut) || !map_check_rect(ut))
	{
		return (0);
	}
	return (1);
}

int	map_check_wall(t_ut *ut)
{
	int	i;

	i = 0;
	while (ut->map[0][i])
	{
		if (ut->map[0][i] != '1')
		{
			ft_putstr_fd("Error\nproblem with up wall", 0);
			return (0);
		}
		i++;
	}
	i = 0;
	while ((size_t)i < ft_strlen(ut->map[ut->map_size - 1]))
	{
		if (ut->map[ut->map_size - 1][i] != '1')
		{
			ft_putstr_fd("Error\nproblem with down wall", 0);
			return (0);
		}
		i++;
	}
	return (1);
}
