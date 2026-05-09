/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:14:30 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/09 14:06:41 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_id(char *s, t_flags *flags)
{
	if (!ft_strncmp(s, "NO ", 3))
		return (flags->id->no = 1, 1);
	else if (!ft_strncmp(s, "SO ", 3))
		return (flags->id->so = 1, 1);
	else if (!ft_strncmp(s, "WE ", 3))
		return (flags->id->we = 1, 1);
	else if (!ft_strncmp(s, "EA ", 3))
		return (flags->id->ea = 1, 1);
	else if (!ft_strncmp(s, "F ", 2))
		return (flags->id->f = 1, 1);
	else if (!ft_strncmp(s, "C ", 2))
		return (flags->id->c = 1, 1);
	return (0);
}

int	is_id_line(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (is_id(&str[i], flags))
		return (1);
	return (0);
}

int	parse_id_line(char *str, t_flags *flags, t_configs *configs)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (!tmp || !tmp[0])
		return (0);
	if (flags->id->no && flags->id->so && flags->id->we
		&& flags->id->ea && flags->id->f && flags->id->c)
		flags->ids_complete = 1;
	if (flags->id->no && !configs->no)
		return (place_conf(configs, tmp, 'N'));
	else if (flags->id->so && !configs->so)
		return (place_conf(configs, tmp, 'S'));
	else if (flags->id->we && !configs->we)
		return (place_conf(configs, tmp, 'W'));
	else if (flags->id->ea && !configs->ea)
		return (place_conf(configs, tmp, 'E'));
	else if (flags->id->f && configs->f == -1)
		return (place_color(configs, tmp, 'F'));
	else if (flags->id->c && configs->c == -1)
		return (place_color(configs, tmp, 'C'));
	free_split(tmp);
	return (ft_putstr_fd("Error\nInvalid identifier line\n", 2), 0);
}
