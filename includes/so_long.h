#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97


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

typedef struct	s_ut
{
	char	*map_name;
	char	**map;
	int		map_size;
	int		map_exist;
	int		is_spawn;
	int		is_exit;
	int		collect;
	size_t	length;
}				t_ut;

void	get_map_size(t_ut *ut);
void	map_malloc(t_ut *ut);
int		get_next_line(int fd, char **line);
void	print_map(t_ut *ut);
void	ft_free(t_ut *ut);
int		is_map(t_ut *ut);
int		map_check(t_ut *ut);
int		map_check_wall(t_ut *ut);
int		map_check_side_wall(t_ut *ut);
int		map_check_spawn(t_ut *ut);
int		map_check_rect(t_ut *ut);


#endif