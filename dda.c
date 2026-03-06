#include "cub3D.h"

int	check(double x, double y,  char **map)
{
	if (map[(int)(y / SIDE)][(int)(x / SIDE)] == '1')
		return (1);
	return (0);
}

double	get_dx(t_player player)
{
	double	i;

	i = 0;
	while (i < player.x)
		i += SIDE;
	if (player.vector.x < 0)
		i -= SIDE;
	return (i - player.x);


	// if (player.vector.x > 0)
	// 	return (ceil(player.x) - player.x);
	// return (floor(player.x) - player.x);
}

double	get_dy(t_player player)
{
	double	i;

	i = 0;
	while (i < player.y)
		i += SIDE;
	if (player.vector.y < 0)
		i -= SIDE;
	return (i - player.y);

	// if (player.vector.y > 0)
	// 	return (ceil(player.y) - player.y);
	// return (floor(player.y) - player.y);
}

t_point	forward_x(t_player player, char **map)
{
	double	step;

	step = 1;
	player.x = ceil(player.x);
	if (player.vector.x < 0)
	{
		player.x--;
		step = -1;
	}
	while (1)
	{
		if (check(player.x, player.y, map))
			return ((t_point){.x = player.x, .y = player.y, .color = 0x00ff00});
		player.x += step;
	}
}

t_point	forward_y(t_player player, char **map)
{
	double	step;

	step = 1;
	player.y = ceil(player.y);
	if (player.vector.y < 0)
	{
		player.y--;
		step = -1;
	}
	while (1)
	{
		if (check(player.x, player.y, map))
			return ((t_point){.x = player.x, .y = player.y, .color = 0x00ff00});
		player.y += step;
	}
}

t_point	dda(t_player player, char **map)
{
	double	k;
	double	h;
	double	l;
	double	dy;
	double	dx;

	if (player.vector.x == 0)
		return (forward_y(player, map));
	if (player.vector.y == 0)
		return (forward_x(player, map));
	///////
	int x_dir = (player.vector.x > 0) ? 1 : -1;
	int y_dir = (player.vector.y > 0) ? 1 : -1;
	///////
	k = player.vector.y / player.vector.x;
	
	dy = get_dy(player);
	dx = get_dx(player);
	h = fabs(k * dx) * y_dir;
	l = fabs(dy / k) * x_dir;
	while (1)
	{
		// printf("k: %f, dx: %f, dy: %f, x: %f, y: %f\n", k, dx, dy, player.x, player.y);
		if (fabs(h) > fabs(dy))
		{
			draw_square(3, player.x + l, player.y + dy, (*datay)->params);
			if (check(player.x + l, player.y + dy, map))
				return ((t_point){.x = player.x + l, .y = player.y + dy, .color = 0x00ff00});
			dy += SIDE * y_dir;
			l += SIDE * x_dir / fabs(k);

		}//changed SIDE to 1
		else
		{
			draw_square(3, player.x + dx, player.y + l, (*datay)->params);
			if (check(player.x + dx, player.y + l, map))
				return ((t_point){.x = player.x + dx, .y = player.y + l, .color = 0x00ff00});
			dx += SIDE * x_dir;
			h += SIDE * y_dir * fabs(k);
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