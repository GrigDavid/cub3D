/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/02/05 23:00:01 by rababaya         ###   ########.fr       */
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

static void	init_id(t_id *id)
{
	id->so = 0;
	id->no = 0;
	id->ea = 0;
	id->we = 0;
	id->c = 0;
	id->f = 0;
}

int	ft_is_whitespace(char c)
{
	return(c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
}

int	only_nl(char *str)
{
	int	i;
	while(ft_is_whitespace(str[i])
		i++;
	if(str[i] != 0)
		return (0);
	return (1);
}

int	parse_map(int fd)
{
	///// add is_map_line is_id_line parse_map_line parse_id_line and make all flags just 1 structure
	int		seen_content;
	int		ids_complete;
	int		map_started;
	int		line_count;
	t_id	*id;
	char	*str;

	id = (t_id *)malloc(sizeof(t_id));
	init_id(id);
	line_count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		line_count++;
		if (only_nl(str))
		{
			free(str);
			continue ;
		}
		seen_content = 1;
		if (!map_started)
		{
			if (is_id_line(str))
			{
				if (!parse_id_line(str))
					return (free(str), ft_putstr_fd("Error\nInvalid identifier line\n", 2), 0);
			}
			else if (is_map_line(str))
			{
				map_started = 1;
				if (!parse_map_line(str))
					return (free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
			}
			else
            	return (free(str), ft_putstr_fd("Error\nInvalid line before map\n", 2), 0);
		}
		else if (ids_complete)
		{
			if (!is_map_line(str))
				return (free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
			if (!parse_map_line(str))
				return (free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
		}
		else
			return (free(str), ft_putstr_fd("Error\nMissing Ids\n", 2), 0);
		free(str);
	}
	if (!line_count || !seen_content)
		return(ft_putstr_fd("Error\nEmpty map\n", 2), 0);
	if (!map_started)
		return(ft_putstr_fd("Error\nNo map\n", 2), 0);
	return (1);
}
