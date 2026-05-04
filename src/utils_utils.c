/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:46:12 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 16:53:11 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
