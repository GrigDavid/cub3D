/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:14:30 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/07 18:44:16 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	safe_place(t_configs *config, char **spl, char config_name)
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

int	parse_id_line(char *str, t_flags *flags)
{
	int		i;
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (!tmp || !tmp[0])
		return (0);
	i = 0;
	if (flags->id->no && !flags->configs->no)
		return (safe_place(flags->configs, tmp, 'N'));
	else if (flags->id->so && !flags->configs->so)
		return (safe_place(flags->configs, tmp, 'S'));
	else if (flags->id->we && !flags->configs->we)
		return (safe_place(flags->configs, tmp, 'W'));
	else if (flags->id->ea && !flags->configs->ea)
		return (safe_place(flags->configs, tmp, 'E'));
	else if (flags->id->f && flags->configs->f == -1)
		return (safe_place(flags->configs, tmp, 'F')); /////
	else if (flags->id->c && flags->configs->c == -1)
		return (safe_place(flags->configs, tmp, 'C')); /////
	free_split(tmp);
	return (0);
}
