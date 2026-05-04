/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:29:54 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 18:07:32 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_vert_line(t_data *data, t_line line, t_point p)
{
	int			height;
	t_params	*pr;
	int			x;
	int			y;
	int			i;

	pr = data->params;
	x = line.x;
	if (x < 0 || x >= pr->win_width)
		return ;
	height = line.height;
	if (height >= pr->win_height)
		height = pr->win_height;
	y = (pr->win_height - height) / 2;
	i = 0;
	while (i < y)
		*(unsigned int *)(pr->img_addr + (i++) * pr->line_length
				+ x * (pr->bits_per_pixel / 8)) = data->configs->c;
	draw_texture(data, line, p, data->texture[txt_side(data->player, p)]);
	y = (pr->win_height + height) / 2;
	while (y < pr->win_height)
		*(unsigned int *)(pr->img_addr + (y++) * pr->line_length
				+ x * (pr->bits_per_pixel / 8)) = data->configs->f;
}
