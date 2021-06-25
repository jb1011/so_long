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
	print_map(ut);
}