/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:14:30 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/17 22:06:28 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	place_conf(t_configs *config, char **spl, char config_name)
{
	char	*target;

	if (!colors_not_set(config) && !colors_are_complete(config))
		return (free_split(spl), ft_putstr_fd("Error\nWrong config order", 2), 0);
	if (spl[1] == NULL || spl[2] != NULL)
		return (free_split(spl), ft_putstr_fd("Error\nInvalid path element count", 2), 0);
	target = ft_strtrim(spl[1], "\n");
	if (!target)
		return (free_split(spl), 0);
	if (config_name == 'N')
		config->no = target;
	else if (config_name == 'S')
		config->so = target;
	else if (config_name == 'E')
		config->ea = target;
	else if (config_name == 'W')
		config->we = target;
	free_split(spl);
	return (1);
}

int	place_color(t_configs *config, char **spl, char config_name)
{
	int		rgb[3];
	char	**color_split;

	if (!textures_not_set(config) && !textures_are_complete(config))
		return (free_split(spl), ft_putstr_fd("Error\nWrong config order", 2), 0);
	if (spl[1] == NULL || spl[2] != NULL)
		return (free_split(spl), ft_putstr_fd("Error\nInvalid color element count", 2), 0);
	color_split = ft_split(spl[1], ',');
	if (!color_split || !color_split[0] || !color_split[1] || !color_split[2] || color_split[3])
		return (free_split(spl), free_split(color_split), ft_putstr_fd("Error\nInvalid color format", 2), 0);
	rgb[0] = ft_atoi(color_split[0]);
	rgb[1] = ft_atoi(color_split[1]);
	rgb[2] = ft_atoi(color_split[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (free_split(spl), free_split(color_split), ft_putstr_fd("Error\nColor values must be between 0 and 255", 2), 0);
	if (config_name == 'F')
		config->f = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	else if (config_name == 'C')
		config->c = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	free_split(spl);
	free_split(color_split);
	return (1);
}

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
	if (flags->id->no && flags->id->so && flags->id->we &&
			flags->id->ea && flags->id->f && flags->id->c)
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
