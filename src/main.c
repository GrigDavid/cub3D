//https://youtu.be/NbSee-XM7WA?si=nx_mxe-1iqoI4h1p
//https://lodev.org/cgtutor/raycasting.html

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data *data;
	int		fd;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	if (!check_valid_file(argv[1], ".cub"))
		return (ft_putstr_fd("Error\nInvalid input file\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCould not open input file\n", 2), 1);
	if (init_data(&data))
		return (1);
	data->configs = parse_cub(fd);
	if (!data->configs)
		return (close(fd), 1);//add data destruction later
	if (!validate_cub(data))
		return (close(fd), 1);//add data destruction later
	data->texture[NW] = read_texture(data, data->configs->no);
	if (!data->texture[NW])
		return (close(fd), 1);//add data destruction later
	data->texture[SW] = read_texture(data, data->configs->so);
	if (!data->texture[SW])
		return (close(fd), 1);//add data destruction later
	data->texture[EW] = read_texture(data, data->configs->ea);
	if (!data->texture[EW])
		return (close(fd), 1);//add data destruction later
	data->texture[WW] = read_texture(data, data->configs->we);
	if (!data->texture[WW])
		return (close(fd), 1);//add data destruction later
	mlx_hook(data->params->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->params->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->params->mlx, movement, data);
	mlx_loop(data->params->mlx);
	return (0);
}
