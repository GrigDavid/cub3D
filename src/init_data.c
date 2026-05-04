/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:07:01 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 12:54:45 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	nullify_data(t_data *data)
{
	data->configs = NULL;
	data->texture[0] = NULL;
	data->texture[1] = NULL;
	data->texture[2] = NULL;
	data->texture[3] = NULL;
	data->params = NULL;
	data->player = NULL;
	data->keypress = NULL;
}

void	free_texture(t_texture *txt, t_params *params)
{
	if (!txt)
		return ;
	if (txt->img)
		mlx_destroy_image(params->mlx, txt->img);
	free(txt);
}

void	free_params(t_params *params)
{
	if (params->img)
		mlx_destroy_image(params->mlx, params->img);
	if (params->win)
		mlx_destroy_window(params->mlx, params->win);
	if (params->mlx)
	{
		mlx_destroy_display(params->mlx);
		free(params->mlx);
	}
	free(params);
}

void	free_configs(t_configs *configs)
{
	if (!configs)
		return ;
	if (configs->no)
		free(configs->no);
	if (configs->so)
		free(configs->so);
	if (configs->we)
		free(configs->we);
	if (configs->ea)
		free(configs->ea);
	if (configs->map)
	{
		if (configs->map->height > 0)
			free_map(configs->map, configs->map->height);
		else
			free(configs->map);
	}
	free(configs);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->texture[0])
		free_texture(data->texture[0], data->params);
	if (data->texture[1])
		free_texture(data->texture[1], data->params);
	if (data->texture[2])
		free_texture(data->texture[2], data->params);
	if (data->texture[3])
		free_texture(data->texture[3], data->params);
	if (data->player)
		free(data->player);
	if (data->keypress)
		free(data->keypress);
	if (data->configs)
		free_configs(data->configs);
	if (data->params)
		free_params(data->params);
	free(data);
}

int	init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (1);
	nullify_data(*data);
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	if (!(*data)->player)
		return (free(*data), 1);
	if (init_keypress(*data))
		return (free_data(*data), 1);
	(*data)->params = (t_params *)malloc(sizeof(t_params));
	if (!((*data)->params))
		return (free_data(*data), 1);
	(*data)->params->win_height = 1080;
	(*data)->params->win_width = 1920;
	(*data)->params->mlx = mlx_init();
	if (!(*data)->params->mlx)
		return (free_data(*data), 1);
	(*data)->params->win = mlx_new_window((*data)->params->mlx,
			(*data)->params->win_width, (*data)->params->win_height, "cub3D");
	if (!(*data)->params->win)
		return (free_data(*data), 1);
	(*data)->params->img = mlx_new_image((*data)->params->mlx,
			(*data)->params->win_width, (*data)->params->win_height);
	if (!(*data)->params->img)
		return (free_data(*data), 1);
	(*data)->params->img_addr = mlx_get_data_addr((*data)->params->img,
			&((*data)->params->bits_per_pixel), &((*data)->params->line_length),
			&((*data)->params->endian));
	gettimeofday(&(*data)->time, NULL);
	return (0);
}
