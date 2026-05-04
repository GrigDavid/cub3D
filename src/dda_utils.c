/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:22:54 by dgrigor2          #+#    #+#             */
/*   Updated: 2026/05/04 19:23:34 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_dx(t_player player)
{
	double	i;

	i = 0;
	i = floor(player.x / SIDE) * SIDE;
	if (player.vector.x > 0)
		i += SIDE;
	return (i - player.x);
}

double	get_dy(t_player player)
{
	double	i;

	i = 0;
	i = floor(player.y / SIDE) * SIDE;
	if (player.vector.y > 0)
		i += SIDE;
	return (i - player.y);
}
