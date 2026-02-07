/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:07:55 by rababaya          #+#    #+#             */
/*   Updated: 2026/02/07 16:33:17 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define STEP 2

# include <unistd.h>
# include <stdio.h>//
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "pars.h"

# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_keypress
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keypress;

typedef struct s_mlx
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
}	t_mlx;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player
{
	float		x;
	float		y;
	t_vector	vector;
}	t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	char		**map;
	t_player	*player;
	t_keypress	*keypress;
}	t_data;

typedef struct s_line
{
	int	x;
	int	height;
}	t_line;

int	cast_ray(t_player *player, char **map);
int	init_data(t_data **data);

int	parse_map(int fd);
int	check_valid_input_file(char *filename);

#endif