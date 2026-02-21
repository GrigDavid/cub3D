#include "cub3D.h"

int	check(t_point p, char **map)
{
	if (map[(int)ceil(p.y) / SIDE][(int)ceil(p.x) / SIDE] == '1')
		return (1);
	if (map[(int)ceil(p.y) / SIDE][(int)floor(p.x) / SIDE] == '1')
		return (1);
	if (map[(int)floor(p.y) / SIDE][(int)ceil(p.x) / SIDE] == '1')
		return (1);
	if (map[(int)floor(p.y) / SIDE][(int)floor(p.x) / SIDE] == '1')
		return (1);
	return (0);
}

double	distance_sq(t_point a, t_point b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double	get_y(double x, t_vector dir)
{
	if (dir.x == 0.0)
	{
		return (0.0);
	}
	return (x * dir.y / dir.x);
}

double	get_x(double y, t_vector dir)
{
	if (dir.y == 0.0)
	{
		return (0.0);
	}
	return (y * dir.x / dir.y);
}

t_point	forward_x(t_player player, char **map);

t_point	forward_y(t_player player, char **map);

t_point	dda_2(t_player player, char **map)
{
	//this is another approach to writing DDA since the previous one is too complicated

	t_vector	dir = player.vector;
	t_point		pos = {.x = player.x, .y = player.y};
	double		delta_x;
	double		delta_y;
	double		moved_x;
	double		moved_y;
	double		dist_x;
	double		dist_y;

	if (dir.x == 0)
		return (forward_y(player, map));
	if (dir.y == 0)
		return (forward_x(player, map));
	delta_x = fabs(1 / dir.x);
	delta_y = fabs(1 / dir.y);
	moved_x = 0;
	moved_y = 0;
	while (1)
	{

	}





}

t_point	dda(t_player player, char **map)
{
	t_vector	dir = player.vector;
	t_point		pos = {.x = player.x, .y = player.y};
	t_point		colx = pos;
	t_point		coly = pos;
	double		x_step;
	double		y_step;

	if (dir.x == 0)
	{
		if (dir.y > 0)
		{
			y_step = 1;
			coly.y = ceil(coly.y);
		}
		else
		{
			y_step = -1;
			coly.y = floor(coly.y);
		}
		while (1)
		{
			if (check(coly, map))
				return (coly);
			coly.y += y_step;
		}
	}
	if (dir.y == 0)
	{
		if (dir.x > 0)
		{
			x_step = 1;
			colx.x = ceil(colx.x);
		}
		else
		{
			x_step = -1;
			colx.x = floor(colx.x);
		}
		while (1)
		{
			if (check(colx, map))
				return (colx);
			colx.x += x_step;
		}
	}
	if (dir.x > 0)
	{
		colx.x = ceil(pos.x);
		colx.y += get_y(colx.x - pos.x, dir);
		x_step = 1.0;
	}
	else
	{
		colx.x = floor(pos.x);
		colx.y += get_y(pos.x - colx.x, dir);
		x_step = -1.0;
	}
	if (dir.y > 0)
	{
		coly.y = ceil(pos.y);
		coly.x += get_x(coly.y - pos.y, dir);
		y_step = 1.0;
	}
	else
	{
		coly.y = floor(pos.y);
		coly.x += get_x(pos.y - coly.y, dir);
		y_step = -1.0;
	}
	while (1)
	{
		if (distance_sq(colx, pos) > distance_sq(coly, pos))
		{
			if (check(coly, map))
				return (coly);
			coly.y += y_step;
			coly.x += get_x(fabs(pos.y - coly.y), dir);
		}
		else
		{
			if (check(colx, map))
				return (colx);
			colx.x += x_step;
			colx.y += get_y(fabs(pos.x - colx.x), dir);
		}
	}
}














/*
	char	**map = [
		[1111111111111111111]
		[1000000000000000001]
		[1000000000000000001]
		[1000000000000000001]
		[1000000000000000001]
		[100000000N000000001]
		[1000000000000000001]
		[1000000000000000001]
		[1000000000000000001]
		[1111111111111111111]
	]
*/