/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:24:44 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 16:52:28 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check(double x, double y, t_vector v, char **map)
{
	int		map_x;
	int		map_y;
	double	eps;

	eps = 0.0001;
	if (v.x < 0)
		x -= eps;
	if (v.y < 0)
		y -= eps;
	map_x = (int)(x / SIDE);
	map_y = (int)(y / SIDE);
	return (map[map_y][map_x] == '1');
}

double	get_dx(t_player player)
{
	double	i;

	i = 0;
	i = floor(player.x / SIDE) * SIDE;
	if (player.vector.x > 0)
		i += SIDE;
	return (i - player.x);
}

double	get_dy(t_player player)
{
	double	i;

	i = 0;
	i = floor(player.y / SIDE) * SIDE;
	if (player.vector.y > 0)
		i += SIDE;
	return (i - player.y);
}

t_point	forward_x(t_player player, char **map)
{
	double	step;

	step = SIDE;
	player.x += get_dx(player);
	if (player.vector.x < 0)
		step = -SIDE;
	while (1)
	{
		if (check(player.x, player.y, player.vector, map))
			return ((t_point){.x = player.x, .y = player.y, .wall = VER});
		player.x += step;
	}
}

t_point	forward_y(t_player player, char **map)
{
	double	step;

	step = SIDE;
	player.y += get_dy(player);
	if (player.vector.y < 0)
		step = -SIDE;
	while (1)
	{
		if (check(player.x, player.y, player.vector, map))
			return ((t_point){.x = player.x, .y = player.y, .wall = HOR});
		player.y += step;
	}
}

t_point	cycle(t_dda vars, t_player player, char **map)
{
	while (1)
	{
		if (vars.h > fabs(vars.dy))
		{
			if (check(player.x + vars.x_dir * vars.l, player.y + vars.dy, player.vector, map))
				return ((t_point){.x = player.x + vars.x_dir * vars.l, .y = player.y + vars.dy, .wall = HOR});
			vars.dy += SIDE * vars.y_dir;
			vars.l += SIDE / vars.k;
		}
		else
		{
			if (check(player.x + vars.dx, player.y + vars.y_dir * vars.h, player.vector, map))
				return ((t_point){.x = player.x + vars.dx, .y = player.y + vars.y_dir * vars.h, .wall = VER});
			vars.dx += SIDE * vars.x_dir;
			vars.h += SIDE * vars.k;
		}
	}
}

t_point	dda(t_player player, char **map)
{
	t_dda vars;

	if (fabs(player.vector.x) < 0.00000001)
		return (forward_y(player, map));
	if (fabs(player.vector.y) < 0.00000001)
		return (forward_x(player, map));
	vars.x_dir = -1;
	if (player.vector.x > 0)
		vars.x_dir = 1;
	vars.y_dir = -1;
	if (player.vector.y > 0)
		vars.y_dir = 1;
	vars.k = fabs(player.vector.y / player.vector.x);
	vars.dy = get_dy(player);
	vars.dx = get_dx(player);
	vars.h = fabs(vars.k * vars.dx);
	vars.l = fabs(vars.dy / vars.k);
	return (cycle(vars, player, map));
}
