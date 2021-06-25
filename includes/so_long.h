#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct  s_ut
{
	char	*map_name;
	char	**map;
	int		map_size;
	int		map_exist;
}               t_ut;

void	get_map_size(t_ut *ut);
void	map_malloc(t_ut *ut);
int		get_next_line(int fd, char **line);
void	print_map(t_ut *ut);
void	ft_free(t_ut *ut);
int		is_map(t_ut *ut);

#endif