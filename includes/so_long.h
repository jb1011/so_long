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

typedef struct	s_text
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_height;
	int		endian;
}				t_text;

typedef struct	s_ut
{
	char	*map_name;
	char	**map;
	int		map_size;
	int		map_exist;
	int		is_spawn;
	int		is_exit;
	int		collect;
	int		len;
	size_t	length;
	void	*mlx_ptr;
	void	*win_ptr;
	t_text	text[5];
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
void	window_init(t_ut *ut);
int		get_text(t_ut *ut);
void	ft_destroy_text(t_ut *ut);
void	display_text(t_ut *ut);

#endif