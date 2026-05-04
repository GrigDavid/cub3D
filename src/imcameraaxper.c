/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imcameraaxper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:31:38 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 12:42:36 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	distance(t_player player, t_point p)
{
	return (hypot(player.x - p.x, player.y - p.y));
}

t_vector	normalise(t_vector v)
{
	double	len;

	len = hypot(v.x, v.y);
	v.x /= len;
	v.y /= len;
	return (v);
}

t_vector	calculate_step(t_vector start, int width)
{
	t_vector	end;

	end = start;
	rotate(&end, (double)FOV);
	return (div_vector_num(sub_vector(end, start), width));
}

t_vector	camera_to_point(t_player camera, t_point p)
{
	t_vector	tmp;

	tmp.x = p.x - camera.x;
	tmp.y = p.y - camera.y;
	return (tmp);
}

void	imcameraaxper(t_data *data, char **map)
{
	t_player	camera;
	t_line		line;
	t_point		p;
	t_vector	start;
	t_vector	step;

	start = data->player->vector;
	rotate(&start, -(double)FOV / 2);
	step = calculate_step(start, data->params->win_width);
	line.x = 0;
	camera.vector = start;
	camera.x = data->player->x;
	camera.y = data->player->y;
	while (line.x < data->params->win_width)
	{
		p = dda(camera, map);
		line.height = data->params->win_height / scalar_mul(
				camera_to_point(camera, p), data->player->vector) * SIDE;
		draw_vert_line(data, line, p);
		(line.x)++;
		camera.vector = sum_vector(camera.vector, step);
	}
}
