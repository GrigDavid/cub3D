#include "cub3D.h"

static void	rotate(t_vector *vector, double thetta)
{
	double old_x = vector->x;
	double old_y = vector->y;

    vector->x = old_x * cos(thetta) - old_y * sin(thetta);
    vector->y = old_x * sin(thetta) + old_y * cos(thetta);
}

double	distance(t_player player, t_point p)
{
	return (sqrt(pow(player.x - p.x, 2) + pow(player.y - p.y, 2)));
}

// void	imcameraaxper(t_data *data, char **map)
// {
// 	t_line		line;
// 	t_player	camera;
// 	t_point		p1;
// 	t_point		p2;

// 	camera = *(data->player);
// 	rotate(&(camera.vector), -pi() / 2);
// 	p1.x = camera.vector.x;
// 	p1.y = camera.vector.y;
// 	rotate(&(camera.vector), pi());
// 	p2.x = camera.vector.x;
// 	p2.y = camera.vector.y;
	
// }
void	imcameraaxper(t_data *data, char **map)
{
	t_player	camera;
	t_line		line;
	t_point		p;
	double		thetta;

	thetta = -FOV / 2;
	camera = *(data->player);
	rotate(&(camera.vector), -0.3);
	line.x = 0;
	while (thetta < FOV / 2)
	{
		rotate(&(camera.vector), FOV / data->params->win_width);//replace 19*SIDE with actual scr
		p = dda(camera, map);
		// draw_square(10, p.x, p.y, data->params);
		line.height = data->params->win_height / distance(*(data->player), p) * SIDE;
		draw_vert_line(data->params, &line);
		(line.x)++;
		thetta +=  FOV /data->params->win_width;
	}
}