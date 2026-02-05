/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:07:41 by rababaya          #+#    #+#             */
/*   Updated: 2026/02/05 21:07:42 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_parse(t_data *data)
{
	//this is just a test function	
	data->map = ft_split("1111111111111111111\
1000000000000000001\
1000000000000000001\
1000000000000000001\
1000000000000000001\
100000000N000000001\
1000000000000000001\
1000000000000000001\
1000000000000000001\
1111111111111111111", '\n');
	if (!data->map)
		return (-1);
	return (0);
}

int	init_keypress(t_data *data)
{
	data->keypress = (t_keypress *)malloc(sizeof(t_keypress));
	if (!data->keypress)
		return (1);
	data->keypress->w = 0;
	data->keypress->a = 0;
	data->keypress->s = 0;
	data->keypress->d = 0;
	data->keypress->left = 0;
	data->keypress->right = 0;
	return (0);
}

int	init_data(t_data **data)
{//BEWARE: malloc protections are almost non-existant	:)
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (1);
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	if (!(*data)->player)
		return (free(*data), 1);
	if (init_keypress(*data))
		return (1);
	(*data)->player->x = 600;
	(*data)->player->y = 600;
	(*data)->player->vector.x = 0;
	(*data)->player->vector.y = 1;
	if (map_parse(*data))
		return (1);//
	(*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!((*data)->mlx))
		return (free((*data)->player), free(*data), 1);
	(*data)->mlx->win_height = 1080;
	(*data)->mlx->win_width = 1920;
	(*data)->mlx->mlx = mlx_init();
	if (!(*data)->mlx->mlx)
		return (1);
	(*data)->mlx->win = mlx_new_window((*data)->mlx->mlx, (*data)->mlx->win_width, (*data)->mlx->win_height, "cub3D");
	(*data)->mlx->img = mlx_new_image((*data)->mlx->mlx, (*data)->mlx->win_width, (*data)->mlx->win_height);
	(*data)->mlx->img_addr = mlx_get_data_addr((*data)->mlx->img, &((*data)->mlx->bits_per_pixel), &((*data)->mlx->line_length), &((*data)->mlx->endian));
	return (0);
}
