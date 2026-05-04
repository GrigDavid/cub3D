/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:00:00 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 17:57:09 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*copy_map(t_map *map)
{
	int		i;
	t_map	*copy;

	copy = init_map(map->height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy->map[i] = ft_strdup(map->map[i]);
		if (!copy->map[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		++i;
	}
	copy->height = map->height;
	copy->max_width = map->max_width;
	return (copy);
}

void	set_player(t_data *data, int x, int y)
{
	data->player->x = x + 0.5;
	data->player->y = y + 0.5;
	if (data->configs->map->map[y][x] == 'N')
	{
		data->player->vector.x = 0;
		data->player->vector.y = -1;
	}
	else if (data->configs->map->map[y][x] == 'S')
	{
		data->player->vector.x = 0;
		data->player->vector.y = 1;
	}
	else if (data->configs->map->map[y][x] == 'E')
	{
		data->player->vector.x = 1;
		data->player->vector.y = 0;
	}
	else if (data->configs->map->map[y][x] == 'W')
	{
		data->player->vector.x = -1;
		data->player->vector.y = 0;
	}
}

int	flood_fill(t_map *map, int x, int y)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0 || x >= map->max_width)
		return (0);
	if (!map->map[y])
		return (0);
	len = ft_strlen(map->map[y]);
	if (x >= len)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == '2')
		return (1);
	map->map[y][x] = '2';
	if (!flood_fill(map, x - 1, y))
		return (0);
	if (!flood_fill(map, x + 1, y))
		return (0);
	if (!flood_fill(map, x, y - 1))
		return (0);
	if (!flood_fill(map, x, y + 1))
		return (0);
	return (1);
}
