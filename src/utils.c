/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:49:11 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/07 16:56:03 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_whitespace(char c)
{
	return (c == 32);
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
