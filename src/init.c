/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:12:52 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/17 21:50:40 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*init_map(int height)
{
	t_map	*map;

	if (height <= 0)
		return (ft_putstr_fd("Error: invalid map height.\n", 2), NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	map->height = height;
	map->max_width = -1;
	return (map);
}

void	init_id(t_flags *flags)
{
	flags->id->so = 0;
	flags->id->no = 0;
	flags->id->ea = 0;
	flags->id->we = 0;
	flags->id->c = 0;
	flags->id->f = 0;
}
void	init_configs(t_configs *configs)
{
	configs->ea = NULL;
	configs->no = NULL;
	configs->so = NULL;
	configs->we = NULL;
	configs->f = -1;
	configs->c = -1;
}

void	trim_newlines(char **src)
{
	int		len;
	char	*new;

	if (!src || !*src)
		return ;
	len = ft_strlen(*src);
	while (len > 0 && (*src)[len - 1] == '\n')
		len--;
	new = ft_substr(*src, 0, len);
	free(*src);
	*src = ft_strdup(new);
	free(new);
}

t_map_list	*new_node(char **val)
{
	t_map_list	*node;

	node = (t_map_list *)malloc(sizeof(t_map_list));
	if (!node)
		return (NULL);
	trim_newlines(val);
	node->row = ft_strdup(*val);
	node->next = NULL;
	return (node);
}
