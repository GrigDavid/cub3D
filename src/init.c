/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:12:52 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/07 15:34:58 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_id(t_flags *flags)
{
	flags->id->so = 0;
	flags->id->no = 0;
	flags->id->ea = 0;
	flags->id->we = 0;
	flags->id->c = 0;
	flags->id->f = 0;
}
void	init_configs(t_flags *flags)
{
	flags->configs->ea = NULL;
	flags->configs->no = NULL;
	flags->configs->so = NULL;
	flags->configs->we = NULL;
	flags->configs->f = -1;
	flags->configs->c = -1;
}
