#include "cub3D.h"



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
	// color *= dist / 10000;
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
		// line.height = data->params->win_height / distance(*(data->player), p) * SIDE;
		line.height = data->params->win_height / scalar_mul((t_vector){.x = p.x - camera.x, .y = p.y - camera.y}, data->player->vector) * SIDE;
		draw_vert_line(data->params, &line, data->texture);
		(line.x)++;
		camera.vector = sum_vector(camera.vector, step);
	}
}
