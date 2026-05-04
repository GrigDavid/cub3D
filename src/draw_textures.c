/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:08:57 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 19:02:42 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	*get_pixel(int x, int y, t_params *p)
{
	return ((unsigned int *)(p->img_addr
		+ y * p->line_length + x * (p->bits_per_pixel / 8)));
}

unsigned int	*get_txt_pixel(int x, int y, t_texture *p)
{
	return ((unsigned int *)(p->addr
		+ y * p->line_length + x * (p->bits_per_pixel / 8)));
}

int	get_texture_x(t_texture *txt, t_point p)
{
	double	local;
	double	wall_x;

	if (p.x - floor(p.x) < p.y - floor(p.y))
		local = fmod(p.y, 100.0);
	else
		local = fmod(p.x, 100.0);
	wall_x = local / 100.0;
	return ((int)(wall_x * txt->width));
}

void	draw_texture(t_data *data, t_line l, t_point p, t_texture *t)
{
	int			y;
	int			txt_x;
	t_params	*pr;
	double		step;
	double		txt_y;

	pr = data->params;
	y = (pr->win_height - l.height) / 2;
	if (l.height > data->params->win_height)
		y = 0;
	txt_x = get_texture_x(t, p);
	step = (double)t->height / (double)l.height;
	txt_y = 0;
	if (l.height > data->params->win_height)
		txt_y = (l.height - data->params->win_height) * step / 2;
	while (y < pr->win_height && txt_y < t->height)
	{
		*(unsigned int *)get_pixel(l.x, y, data->params)
				= *(unsigned int *)get_txt_pixel(txt_x, (int)txt_y, t);
		y++;
		txt_y += step;
	}
}

int	txt_side(t_player *player, t_point p)
{
	t_vector	player_to_p;

	player_to_p.x = p.x - player->x;
	player_to_p.y = p.y - player->y;
	if (p.wall == HOR)
	{
		if (player_to_p.y > 0)
			return (NW);
		return (SW);
	}
	if (player_to_p.x > 0)
		return (WW);
	return (EW);
}
