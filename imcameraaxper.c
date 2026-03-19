#include "cub3D.h"

static t_vector	sum_vector(t_vector a, t_vector b)
{
	return ((t_vector){.x = a.x + b.x, .y = a.y + b.y});
}

static t_vector	sub_vector(t_vector a, t_vector b)
{
	return ((t_vector){.x = a.x - b.x, .y = a.y - b.y});
}

// static t_vector	mul_vector_num(t_vector a, double k)
// {
// 	return ((t_vector){.x = a.x * k, .y = a.y * k});
// }

static t_vector	div_vector_num(t_vector a, double k)
{
	return ((t_vector){.x = a.x / k, .y = a.y / k});
}

static void	rotate(t_vector *vector, double thetta)
{
	double old_x = vector->x;
	double old_y = vector->y;

    vector->x = old_x * cos(thetta) - old_y * sin(thetta);
    vector->y = old_x * sin(thetta) + old_y * cos(thetta);
}


double	distance(t_player player, t_point p)
{
	return (hypot(player.x - p.x, player.y - p.y));
}

unsigned int	color_from_distance(t_player player, t_point p)
{
	unsigned int	color;
	double			dist;

	dist = distance(player, p);
	color = 0x406094;
	color *= dist / 10000;
	return (color);

}

void	imcameraaxper(t_data *data, char **map)
{
	t_player	camera;
	t_line		line;
	t_point		p;
	t_vector	start;
	t_vector	end;
	t_vector	step;

	start = data->player->vector;
	end = data->player->vector;
	rotate(&start, -FOV / 2);
	rotate(&end, FOV / 2);
	step = div_vector_num(sub_vector(end, start), data->params->win_width); 
	line.x = 0;
	camera.vector = start;
	camera.x = data->player->x;
	camera.y = data->player->y;
	while (line.x < data->params->win_width)
	{
		p = dda(camera, map);
		// draw_square(10, p.x, p.y, data->params);
		line.color = color_from_distance(camera, p);
		line.height = data->params->win_height / distance(*(data->player), p) * SIDE;
		draw_vert_line(data->params, &line);
		(line.x)++;
		camera.vector = sum_vector(camera.vector, step);
	}
}
