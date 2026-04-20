/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:40:47 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/20 23:01:19 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_valid_dest(t_configs *configs)
{
	int	fd_north;
	int	fd_south;
	int	fd_east;
	int	fd_west;

	fd_north = open(configs->no, O_RDONLY);
	if (fd_north == -1)
		return (ft_putstr_fd("Error\nInvalid texture file", 2), 0);
	fd_south = open(configs->so, O_RDONLY);
	if (fd_south == -1)
		return (close(fd_north), ft_putstr_fd("Error\nInvalid texture file", 2), 0);
	fd_east = open(configs->ea, O_RDONLY);
	if (fd_east == -1)
		return (close(fd_north), close(fd_south),
			ft_putstr_fd("Error\nInvalid texture file", 2), 0);
	fd_west = open(configs->we, O_RDONLY);
	if (fd_west == -1)
		return (close(fd_north), close(fd_south), close(fd_east),
			ft_putstr_fd("Error\nInvalid texture file", 2), 0);
	close(fd_north);
	close(fd_south);
	close(fd_east);
	close(fd_west);
	return (1);
}
t_map	*copy_map(t_map *map)
{
	int		i;
	t_map	*copy;

	copy = init_map(map->height);
	if (!copy)
		return ( NULL);
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

int	find_player(t_data *data, t_map *map)
{
	int	x;
	int	y;
	int	player_count;

	y = -1;
	player_count = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < (int)ft_strlen(map->map[y]))
		{
			if (!is_valid_char(map->map[y][x]))
				return (ft_putstr_fd("Error\nInvalid char in map", 2), 0);
			if (is_player(map->map[y][x]))
			{
				if (check_player_pos(map, x, y))
					return (0);
				player_count++;
				data->player->x = x + 0.5;
				data->player->y = y + 0.5;
				data->configs->map->map[y][x] = '0';
			}
		}
	}
	if (player_count != 1)
		return (ft_putstr_fd("Error\nWrong player count", 2), 0);
	return (1);
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

int	validate_map(t_data *data)
{
	t_map	*copy;

	if (!data->configs->map)
		return (0);
	copy = copy_map(data->configs->map);
	if (!copy)
		return (0);
	// if (!init_player(data))
	// 	return (free_map(copy, copy->height), 0);
	if (!find_player(data, copy))
		return (free_map(copy, copy->height), 0);
	if (!flood_fill(copy, (int)data->player->x, (int)data->player->y))
	{
		free_map(copy, copy->height);
		return (ft_putstr_fd("Error\nOpen map", 2), 0);
	}
	free_map(copy, copy->height);
	return (1);
}

int validate_cub(t_data *data)
{
	if (!check_valid_file(data->configs->no, ".xpm")
		|| !check_valid_file(data->configs->so, ".xpm")
		|| !check_valid_file(data->configs->ea, ".xpm")
		|| !check_valid_file(data->configs->we, ".xpm"))
		return (0);
	printf("Textures have valid extensions\n");
	if (!validate_map(data))
		return (0);
	if (!check_valid_dest(data->configs))
		return (0);
	return (1);
}
