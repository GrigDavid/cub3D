/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/20 20:43:45 by rababaya         ###   ########.fr       */
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
	flags->id = (t_id *)malloc(sizeof(t_id));
	configs = (t_configs *)malloc(sizeof(t_configs));
	//malloc protections??????
	init_id(flags);
	init_configs(configs);
	flags->line_count = 0;
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
	}
	// if (errno)
	// 	return (free(flags->id), free(flags), NULL);
	
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %d\nC: %d\nline count: %d\n", configs->no, configs->so, configs->we, configs->ea, configs->f, configs->c, flags->line_count);
	for (size_t i = 0; i < 14; i++)
	{
		printf("map line %zu: %s\n", i, configs->map->map[i]);
	}
	
	if (!flags->line_count || !flags->seen_content)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nEmpty map\n", 2), NULL);
	if (!flags->map_started)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nNo map\n", 2), NULL);
	return (configs);
}
