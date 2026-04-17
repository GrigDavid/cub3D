/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:49:11 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/17 20:31:56 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_whitespace(char c)
{
	return (c == 32 || c == '\n');
}

int	only_nl(char *str)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] != 0)
		return (0);
	return (1);
}

int	ft_inset(char target, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (target == src[i])
			return (1);
		++i;
	}
	return (0);
}

void	free_split(char **split)
{
	size_t	i;

	if (!split || !split[0])
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	split = NULL;
}

void	free_map(t_map *map, int size)
{
	if (!map)
		return ;
	while (size-- > 0)
		free(map->map[size]);
	free(map->map);
	free(map);
}

void	free_map_lst(t_map_list *head)
{
	t_map_list	*temp;
	t_map_list	*nxt;

	if (!head)
		return ;
	temp = head;
	while (temp)
	{
		nxt = temp->next;
		free(temp->row);
		free(temp);
		temp = nxt;
	}
}
