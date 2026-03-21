/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/21 13:51:00 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_valid_input_file(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".cub", 5))
		return (0);
	return (1);
}

int	parse_map(int fd)
{
	///// add is_map_line is_id_line parse_map_line parse_id_line and make all flags just 1 structure
	t_flags	*flags;
	char	*str;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->id = (t_id *)malloc(sizeof(t_id));
	flags->configs = (t_configs *)malloc(sizeof(t_configs));
	init_id(flags);
	init_configs(flags);
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
				if (!parse_id_line(str, flags))
					return (free(flags->id), free(flags), free(str), 0);
			}
			// else if (is_map_line(str) && flags->ids_complete)
			// {
			// 	flags->map_started = 1;
			// 	if (!parse_map_line(str))
			// 		return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
			// }
			// else
			// 	return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid line before map\n", 2), 0);
		}
		// else if (flags->ids_complete)
		// {
		// 	if (!is_map_line(str))
		// 		return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
		// 	if (!parse_map_line(str))
		// 		return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
		// }
		// else
		// 	return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nMissing Ids\n", 2), 0);
		free(str);
	}
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %d\nC: %d\nline count: %d\n", flags->configs->no, flags->configs->so, flags->configs->we, flags->configs->ea, flags->configs->f, flags->configs->c, flags->line_count);
	if (errno)
		return (free(flags->id), free(flags), 0);
	if (!flags->line_count || !flags->seen_content)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nEmpty map\n", 2), 0);
	if (!flags->map_started)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nNo map\n", 2), 0);
	return (1);
}
