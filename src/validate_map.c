/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:35:24 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/17 22:28:06 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate(t_data *data)
{
	if (!data->configs)
		return (0);
	if (!check_valid_file(&data->configs->no, ".xpm")
		|| !check_valid_file(&data->configs->so, ".xpm")
		|| !check_valid_file(&data->configs->ea, ".xpm")
		|| !check_valid_file(&data->configs->we, ".xpm"))
		return (0);
	return (1); /////////
}
