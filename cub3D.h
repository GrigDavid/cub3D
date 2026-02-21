#ifndef CUB3D_H
# define CUB3D_H

# define STEP 2
# define SIDE 100

# include <unistd.h>
# include <stdio.h>//
# include <stdlib.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "libft/libft.h"

# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_keypress
{
	int w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keypress;

typedef struct s_params
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
}	t_params;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_point
{
	double			x;
	double			y;
	unsigned int	color;
}	t_point;

typedef struct s_player
{
	double		x;
	double		y;
	t_vector	vector;
}	t_player;

typedef struct s_data
{
	t_params	*params;
	char		**map;
	t_player	*player;
	t_keypress	*keypress;
}	t_data;

typedef struct s_line
{
	int	x;
	int	height;
}	t_line;

// int		cast_ray(t_player	*player, char	**map);
//t_vector	cast_ray(t_player	*player, char	**map);
void		draw_ray_contact(int side, int x, int y, t_params *p);
int			init_data(t_data **data);
void		draw_square(int side, int x, int y, t_params *p);
void		draw_walls(t_data *data);
void		draw_line(t_params *p, t_line *line);
void		delete_square(int side, int x, int y, t_params *p);
void		draw_square(int side, int x, int y, t_params *p);
t_point		dda(t_player player, char **map);

#endif