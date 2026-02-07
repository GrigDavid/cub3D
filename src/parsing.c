/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/02/07 17:02:22 by rababaya         ###   ########.fr       */
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
	return (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13);
}

int	only_nl(char *str)
{
	int	i;

	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] != 0)
		return (0);
	return (1);
}

int	is_id(char *s, t_flags *flags)
{
	if (!ft_strncmp(s, "NO", 2))
		return (flags->id->no = 1, 1);
	else if (!ft_strncmp(s, "SO", 2))
		return (flags->id->so = 1, 1);
	else if (!ft_strncmp(s, "WE", 2))
		return (flags->id->we = 1, 1);
	else if (!ft_strncmp(s, "EA", 2))
		return (flags->id->ea = 1, 1);
	else if (!ft_strncmp(s, "F", 1))
		return (flags->id->f = 1, 1);
	else if (!ft_strncmp(s, "C", 1))
		return (flags->id->c = 1, 1);
	return (0);
}

int	is_id_line(char *str, t_flags *flags)
{
	int	i;

	while (ft_is_whitespace(str[i]))
		i++;
	if (is_id(&str[i], flags))
		return (1);
	return (0);
}

int	parse_id_line(char *str, t_flags *flags)
{
	int	i;
	while (ft_is_whitespace(str[i]))
		i++;
	
}

int	parse_map(int fd)
{
	///// add is_map_line is_id_line parse_map_line parse_id_line and make all flags just 1 structure
	t_flags	*flags;
	char	*str;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->id = (t_id *)malloc(sizeof(t_id));
	init_id(flags->id);
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
					return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid identifier line\n", 2), 0);
			}
			else if (is_map_line(str))
			{
				flags->map_started = 1;
				if (!parse_map_line(str))
					return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
			}
			else
				return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid line before map\n", 2), 0);
		}
		else if (flags->ids_complete)
		{
			if (!is_map_line(str))
				return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
			if (!parse_map_line(str))
				return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
		}
		else
			return (free(flags->id), free(flags), free(str), ft_putstr_fd("Error\nMissing Ids\n", 2), 0);
		free(str);
	}
	if (errno)
		return (free(flags->id), free(flags), 0);
	if (!flags->line_count || !flags->seen_content)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nEmpty map\n", 2), 0);
	if (!flags->map_started)
		return (free(flags->id), free(flags), ft_putstr_fd("Error\nNo map\n", 2), 0);
	return (1)