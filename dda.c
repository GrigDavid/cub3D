#include "cub3D.h"

int	check(double x, double y, t_vector vector, char **map)
{
	// printf("x: %f, y: %f\n", x, y);
	if (vector.x >= 0 && vector.y >= 0 && map[(int)(y / SIDE)][(int)(x / SIDE)] == '1')
		return (1);
	if (vector.x >= 0 && vector.y <= 0 && map[(int)((y - 1) / SIDE)][(int)((x) / SIDE)] == '1')
		return (1);
	if (vector.x <= 0 && vector.y >= 0 && map[(int)((y) / SIDE)][(int)((x - 1) / SIDE)] == '1')
		return (1);
	if (map[(int)((y - 1) / SIDE)][(int)((x - 1) / SIDE)] == '1')
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
			return ((t_point){.x = player.x, .y = player.y, .color = 0x00ff00});
		player.x += step;
	}
}

t_point	forward_y(t_player player, char **map)
{
	double	step;

	step = SIDE;
	player.y += get_dy(player);
	// printf("%f\n", player.y);
	if (player.vector.y < 0)
		step = -SIDE;
	while (1)
	{
		if (check(player.x, player.y, player.vector, map))
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
	k = fabs(player.vector.y / player.vector.x);
	dy = get_dy(player);
	dx = get_dx(player);
	h = fabs(k * dx);
	l = fabs(dy / k);
	// printf("k: %f, h: %f, dx: %f, dy: %f\n", k, h, dx, dy);//
	while (1)
	{
		if (h > fabs(dy))
		{
			// draw_square(3, player.x + x_dir * l, player.y + dy, (*datay)->params);
			if (check(player.x + x_dir * l, player.y + dy, player.vector, map))
				return ((t_point){.x = player.x + x_dir * l, .y = player.y + dy, .color = 0x00ff00});
			dy += SIDE * y_dir;
			l += SIDE / k;
		}
		else
		{
			// draw_square(3, player.x + dx, player.y + y_dir * h, (*datay)->params);
			if (check(player.x + dx, player.y + y_dir * h, player.vector, map))
				return ((t_point){.x = player.x + dx, .y = player.y + y_dir * h, .color = 0x00ff00});
			dx += SIDE * x_dir;
			h += SIDE * k;
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