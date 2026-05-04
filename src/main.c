/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:22:07 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 11:26:57 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://youtu.be/NbSee-XM7WA?si=nx_mxe-1iqoI4h1p
//https://lodev.org/cgtutor/raycasting.html

#include "cub3D.h"

//the wrong texture line when looking at it perpendicular
//texture widening
//texture mirroring
void	print_map(t_map_list *head)
{
	t_map_list	*temp;

	temp = head;
	while (temp)
	{
		printf("%s", temp->row);
		temp = temp->next;
	}
}

t_map_list	*read_to_list(int fd)
{
	t_map_list	*head;
	t_map_list	*temp;
	char		*str;
	int			n;

	n = 0;
	str = get_next_line(fd);
	head = new_node(&str);
	if (!head)
		return (free(str), ft_putstr_fd("Error\nEmpty map file\n", 2), NULL);
	temp = head;
	while (str)
	{
		if (n != 0)
		{
			temp->next = new_node(&str);
			if (!temp->next)
			{
				free(str);
				free_map_lst(head);
				return (NULL);
			}
			temp = temp->next;
		}
		free(str);
		str = get_next_line(fd);
		n++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	int			fd;
	t_map_list	*temp;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	if (!check_valid_file(argv[1], ".cub"))
		return (ft_putstr_fd("Error\nInvalid input file\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCould not open input file\n", 2), 1);
	if (init_data(&data))
		return (1);
	temp = read_to_list(fd);
	if (!temp)
		return (close(fd), free_data(data), 1);
	data->configs = parse_cub(temp);
	if (!data->configs)
		return (close(fd), free_data(data), 1);//add data destruction later
	if (!validate_cub(data))
		return (close(fd), free_data(data), 1);//add data destruction later
	data->texture[NW] = read_texture(data, data->configs->no);
	if (!data->texture[NW])
		return (close(fd), free_data(data), 1);//add data destruction later
	data->texture[SW] = read_texture(data, data->configs->so);
	if (!data->texture[SW])
		return (close(fd), free_data(data), 1);//add data destruction later
	data->texture[EW] = read_texture(data, data->configs->ea);
	if (!data->texture[EW])
		return (close(fd), free_data(data), 1);//add data destruction later
	data->texture[WW] = read_texture(data, data->configs->we);
	if (!data->texture[WW])
		return (close(fd), free_data(data), 1);//add data destruction later
	mlx_hook(data->params->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->params->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->params->mlx, movement, data);
	(void)data->params->mlx;
	mlx_loop(data->params->mlx);
	return (0);
}
