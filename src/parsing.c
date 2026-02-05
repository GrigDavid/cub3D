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

int	parse_map(int fd)
{
	int		line_count;
	t_id	*id;
	char	*str;

	init_id(id);
	line_count = 0;
	str = get_next_line(fd);
	while (str)
	{
		line_count++;
		free(str);
		str = get_next_line(fd);
		if (!str)
			return (0);  ///for now no error code for malloc
		if (ft_strncmp(str, "\n", 2))
			continue ;
		find_ids();
		printf("%s", str);
		
	}
	if (!line_count)
		return(ft_putstr_fd("Error\nEmpty map\n", 2), 0);
	return (1);
}