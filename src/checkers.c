/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:08:01 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/07 18:35:31 by rababaya         ###   ########.fr       */
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

// int	check_first_arg(char *arg)
// {
// 	if (!arg)
// 		return (0);
// 	if ((ft_strncmp(arg, "C", 2) == 0) || (ft_strncmp(arg, "F", 2) == 0)
// 		|| (ft_strncmp(arg, "NO", 3) == 0) || (ft_strncmp(arg, "SO", 3) == 0)
// 		|| (ft_strncmp(arg, "EA", 3) == 0) || (ft_strncmp(arg, "WE", 3) == 0))
// 		return (0);
// 	return (1);
// }
