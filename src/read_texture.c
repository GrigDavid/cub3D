/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:18:11 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 10:18:28 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texture	*read_texture(t_data *data, char *filename)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(data->params->mlx, filename, &(texture->width), &(texture->height));
	if (!texture->img)
		return (free(texture), NULL);
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel), &(texture->line_length), &(texture->endian));
	if (!texture->addr)
		return (free(texture), NULL); //should add image destroy
	return (texture);
}
