/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 16:47:33 by rababaya         ###   ########.fr       */
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

void	free_stuff(t_flags *flags, t_configs *configs, t_map_list *map_list)
{
	free(flags->id);
	free(flags);
	free_configs(configs);
	free_map_lst(map_list);
}

static int	process_node(t_flags *flags, t_configs *configs, t_map_list *node)
{
	if (only_nl(node->row))
		return (1);
	flags->seen_content = 1;
	if (!flags->map_started)
	{
		if (is_id_line(node->row, flags))
		{
			if (parse_id_line(node->row, flags, configs))
				return (1);
			return (-1);
		}
		if (ft_inset(*node->row, "10 "))
		{
			flags->map_started = 1;
			if (parse_map(configs, node))
				return (2);
			return (-1);
		}
		ft_putstr_fd("Error\nInvalid line before map\n", 2);
		return (-1);
	}
	return (1);
}

int	post_checker(t_flags *flags)
{
	if (!flags->line_count || !flags->seen_content)
		return (ft_putstr_fd("Error\nEmpty map\n", 2), 0);
	if (!flags->map_started)
		return (ft_putstr_fd("Error\nNo map\n", 2), 0);
	return (1);
}

t_configs	*parse_cub(t_map_list *map_list)
{
	t_flags		*flags;
	t_configs	*configs;
	t_map_list	*tmp;

	tmp = map_list;
	flags = init_id();
	if (!flags)
		return (NULL);
	configs = init_configs();
	if (!configs)
		return (free(flags->id), free(flags), NULL);
	while (tmp)
	{
		flags->line_count++;
		flags->res = process_node(flags, configs, tmp);
		if (flags->res == -1)
			return (free_stuff(flags, configs, map_list), NULL);
		if (flags->res == 2)
			break ;
		tmp = tmp->next;
	}
	if (!post_checker(flags))
		return (free_stuff(flags, configs, map_list), NULL);
	free_map_lst(map_list);
	return (free(flags->id), free(flags), configs);
}
