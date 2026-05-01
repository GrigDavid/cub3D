/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/01 14:56:55 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_valid_file(char *filename, char *ext)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ext, ft_strlen(ext) + 1))
		return (0);
	return (1);
}

t_configs	*parse_cub(int fd)
{
	t_flags	*flags;
	t_configs	*configs;
	char	*str;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), NULL);
	flags->id = (t_id *)malloc(sizeof(t_id));
	if (!flags->id)
		return (free(flags), ft_putstr_fd("Error\nMemory allocation failed\n", 2), NULL);
	configs = (t_configs *)malloc(sizeof(t_configs));
	if (!configs)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nMemory allocation failed\n", 2), NULL);
	init_id(flags);
	init_configs(configs);
	flags->line_count = 0;
	flags->seen_content = 0;
	flags->map_started = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		flags->line_count++;
		if (only_nl(str))
		{
			free(str);
			continue ;
		}
		flags->seen_content = 1;
		if (!flags->map_started)
		{
			if (is_id_line(str, flags))
			{
				if (!parse_id_line(str, flags, configs))
					return (free(flags->id), free(configs), free(flags), free(str), NULL);
			}
			else if (ft_inset(*str, "10 ") && flags->ids_complete)
			{
				flags->map_started = 1;
				if (!parse_map(configs, &str, fd))
					return (free(flags->id), free(configs), free(flags), free(str), NULL);
				free(str);
				break;
			}
			else
				return (free(flags->id), free(configs), free(flags), free(str), ft_putstr_fd("Error\nInvalid line before map\n", 2), NULL);
		}
		free(str);
	}
	if (!flags->line_count || !flags->seen_content)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nEmpty map\n", 2), NULL);
	if (!flags->map_started)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nNo map\n", 2), NULL);
	free(flags->id);
	free(flags);
	return (configs);
}
