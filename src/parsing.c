/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/03 16:54:03 by rababaya         ###   ########.fr       */
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

t_configs	*parse_cub(t_map_list *map_list)
{
	t_flags	*flags;
	t_configs	*configs;
	t_map_list	*tmp;

	tmp = map_list;
	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->id = (t_id *)malloc(sizeof(t_id));
	if (!flags->id)
		return (free(flags), NULL);
	configs = (t_configs *)malloc(sizeof(t_configs));
	if (!configs)
		return (free(flags->id), free(flags), NULL);
	init_id(flags);
	init_configs(configs);
	flags->line_count = 0;
	flags->seen_content = 0;
	flags->map_started = 0;
	while (tmp)
	{
		flags->line_count++;
		if (only_nl(tmp->row))
		{
			tmp = tmp->next;
			continue ;
		}
		flags->seen_content = 1;
		if (!flags->map_started)
		{
			if (is_id_line(tmp->row, flags))
			{
				if (!parse_id_line(tmp->row, flags, configs))
					return (free(flags->id), free_configs(configs), free(flags), free_map_lst(map_list), NULL);
			}
			else if (ft_inset(*tmp->row, "10 ") && flags->ids_complete)
			{
				flags->map_started = 1;
				if (!parse_map(configs, tmp))
					return (free(flags->id), free_configs(configs), free(flags), free_map_lst(map_list), NULL);
				break;
			}
			else
				return (free(flags->id), free_configs(configs), free(flags), free_map_lst(map_list), ft_putstr_fd("Error\nInvalid line before map\n", 2), NULL);
		}
		tmp = tmp->next;
	}
	free_map_lst(map_list);
	if (!flags->line_count || !flags->seen_content)
		return (free(flags->id), free(flags), free_configs(configs), ft_putstr_fd("Error\nEmpty map\n", 2), NULL);
	if (!flags->map_started)
		return (free(flags->id), free(flags), free_configs(configs), ft_putstr_fd("Error\nNo map\n", 2), NULL);
	return (free(flags->id), free(flags), configs);
}
