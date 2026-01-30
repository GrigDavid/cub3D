#ifndef CUB3D_H
# define CUB3D_H
# include	<unistd.h>
# include	<stdio.h>//
# include	<stdlib.h>
# include	"./minilibx_linux/mlx.h"
# include	"libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_height;
	int		win_width;
} t_mlx;

typedef struct s_player
{
	int		x;
	int		y;
	float	dir;
} t_player;


typedef struct	s_data
{
	char	**map;
	int		player_x;
	int		player_y;
	int		angle;
}t_data;

typedef struct	s_line
{
	int	x;
	int	height;
} t_line;

#endif