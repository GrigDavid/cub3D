/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:49:42 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 13:49:54 by rababaya         ###   ########.fr       */
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
