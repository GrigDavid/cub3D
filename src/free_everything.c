/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:26:52 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 17:27:24 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
