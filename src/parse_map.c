/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:03:05 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/17 21:46:28 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_pointers(t_map_list *head, t_map *map, int i)
{
	if (head)
		free_map_lst(head);
	if (map)
		free_map(map, i);
}

int	check_map_empty_lines(t_map_list *head)
{
	t_map_list	*temp;

	if (!head)
		return (0);
	temp = head;
	while (temp)
	{
		if (ft_strcmp(temp->row, ""))
		{
			ft_putstr_fd("Error\nWrong map", 2);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	replace_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '0';
			++j;
		}
		++i;
	}
}

t_map	*list_to_map(t_map_list *hd, int sz)
{
	int			i;
	t_map		*map;
	t_map_list	*temp;

	if (!hd)
		return (NULL);
	map = init_map(sz);
	if (!map)
		return (free_map_lst(hd), NULL);
	i = -1;
	temp = hd;
	while (temp && ++i < sz)
	{
		if (ft_strcmp(temp->row, "") == 0 && check_map_empty_lines(temp))
			return (free_grdon_map(hd, map, i), NULL);
		map->map[i] = ft_strdup(temp->row);
		if (!map->map[i])
			return (free_grdon_map(hd, map, i), NULL);
		if (map->max_width < ft_strlen(map->map[i]))
			map->max_width = ft_strlen(map->map[i]);
		temp = temp->next;
	}
	return (free_map_lst(hd), map->map[sz] = NULL, replace_spaces(map), map);
}

int	parse_map(t_configs *config, char **first_line, int fd)
{
	int			size;
	char		*line;
	t_map_list	*head;
	t_map_list	*temp;

	if (!textures_are_complete(config) || !colors_are_complete(config))
		return (ft_putstr_fd("Error\nWrong config order", 2), 0);
	head = new_node(first_line);
	if (!head)
		return (0);
	size = 1;
	temp = head;
	line = get_next_line(fd);
	while (line)
	{
		temp->next = new_node(&line);
		temp = temp->next;
		free(line);
		line = get_next_line(fd);
		++size;
	}
	config->map = list_to_map(head, size);
	if (!config->map)
		return (free(line), 0);
	return (free(line), 1);
}
