/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:24:30 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/09 14:32:08 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_digits_only(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}

static int	parse_rgb(char *color_str, int rgb[3])
{
	char	**color_split;

	color_split = ft_split(color_str, ',');
	if (!color_split || !color_split[0]
		|| !color_split[1] || !color_split[2] || color_split[3])
		return (free_split(color_split),
			ft_putstr_fd("Error\nInvalid color format\n", 2), 0);
	if (!is_digits_only(color_split[0]) || !is_digits_only(color_split[1])
		|| !is_digits_only(color_split[2]))
		return (free_split(color_split),
			ft_putstr_fd("Error\nColor values must be numeric\n", 2), 0);
	rgb[0] = ft_atoi(color_split[0]);
	rgb[1] = ft_atoi(color_split[1]);
	rgb[2] = ft_atoi(color_split[2]);
	free_split(color_split);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (ft_putstr_fd("Error\nColor must be between 0-255\n", 2), 0);
	return (1);
}

int	place_color(t_configs *config, char **spl, char config_name)
{
	int	rgb[3];

	if (spl[1] == NULL || spl[2] != NULL)
		return (free_split(spl),
			ft_putstr_fd("Error\nInvalid color element count\n", 2), 0);
	if (!parse_rgb(spl[1], rgb))
		return (free_split(spl), 0);
	if (config_name == 'F')
		config->f = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	else if (config_name == 'C')
		config->c = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	free_split(spl);
	return (1);
}

int	place_conf(t_configs *config, char **spl, char config_name)
{
	char	*target;

	if (spl[1] == NULL || spl[2] != NULL)
		return (free_split(spl),
			ft_putstr_fd("Error\nInvalid path element count\n", 2), 0);
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
