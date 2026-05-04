/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:16:24 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 18:18:05 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define STEP 4
# define SIDE 100
# define FOV 0.9

# include <unistd.h>
# include <stdio.h>//
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "pars.h"

# include <X11/X.h>
# include <X11/keysym.h>

# include <limits.h>
# include <sys/time.h>

enum e_direction
{
	NW = 0,
	SW = 1,
	EW = 2,
	WW = 3
};

enum e_wall
{
	HOR = 0,
	VER = 1
};

typedef struct s_keypress
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keypress;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_texture;

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
	int				wall;
}	t_point;

typedef struct s_player
{
	double		x;
	double		y;
	t_vector	vector;
}	t_player;

typedef struct s_data
{
	unsigned int	top_color;
	unsigned int	floor_color;
	struct timeval	time;
	t_configs		*configs;
	t_texture		*texture[4];
	t_params		*params;
	t_player		*player;
	t_keypress		*keypress;
}	t_data;

typedef struct s_line
{
	int				x;
	int				height;
}	t_line;

typedef	struct s_dda
{
	double	k;
	double	h;
	double	l;
	double	dy;
	double	dx;
	int		x_dir;
	int		y_dir;
} t_dda;

// extern t_data	**datay;
// int		cast_ray(t_player	*player, char	**map);
//t_vector	cast_ray(t_player	*player, char	**map);
void			draw_ray_contact(int side, int x, int y, t_params *p);
int				init_data(t_data **data);
void			draw_square(int side, int x, int y, t_params *p);
void			draw_walls(t_data *data);
void			draw_line(t_params *p, t_line *line);
void			delete_square(int side, int x, int y, t_params *p);
void			draw_square(int side, int x, int y, t_params *p);
t_point			dda(t_player player, char **map);
void			draw_vert_line(t_data *data, t_line line, t_point p);
void			imcameraaxper(t_data *data, char **map);

t_vector		sum_vector(t_vector a, t_vector b);
t_vector		sub_vector(t_vector a, t_vector b);
double			scalar_mul(t_vector a, t_vector b);
t_vector		mul_vector_num(t_vector a, double k);
t_vector		div_vector_num(t_vector a, double k);
void			rotate(t_vector *vector, double thetta);

long long		timedif(struct timeval t1, struct timeval t2);

t_texture		*read_texture(t_data *data, char *filename);

unsigned int	*get_pixel(int x, int y, t_params *p);
unsigned int	*get_txt_pixel(int x, int y, t_texture *p);
int				get_texture_x(t_texture *txt, t_point p);
void			draw_texture(t_data *data, t_line line, t_point p, t_texture *txt);
int				txt_side(t_player *player, t_point p);

t_configs		*parse_cub(t_map_list *map_list);
int				validate_cub(t_data *data);
int				check_valid_file(char *filename, char *ext);

int				place_conf(t_configs *config, char **spl, char config_name);
int				place_color(t_configs *config, char **spl, char config_name);

t_map			*copy_map(t_map *map);
void			set_player(t_data *data, int x, int y);
int				flood_fill(t_map *map, int x, int y);

void			rotate_player(t_player *player, double thetta);
int				movement(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

void			free_data(t_data *data);

#endif
