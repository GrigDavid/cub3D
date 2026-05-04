/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:08:01 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 12:20:14 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	textures_not_set(t_configs *c)
{
	return (!c->no && !c->so && !c->ea && !c->we);
}

int	colors_not_set(t_configs *c)
{
	return (c->c == -1 && c->f == -1);
}

int	textures_are_complete(t_configs *c)
{
	return (c->no && c->so && c->ea && c->we);
}

int	colors_are_complete(t_configs *c)
{
	return (c->c != -1 && c->f != -1);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_player_pos(t_map *map, int x, int y)
{
	return (y == 0 || y == map->height - 1
		|| x == 0 || x == map->max_width - 1);
}
