#include "cub3D.h"

void	draw_line(t_mlx *mlx, t_line *line)
{
	int	height;
	int x;
	
	x = line->x;
	if (x < 0 || x >= mlx->win_width)
		return ;
	height = line->height;
	if (height >= mlx->win_height)
		height = mlx->win_height;
	int y = (mlx->win_height - line->height) / 2;
	int color = 0x00eaff;
	while (y++ < (mlx->win_height + line->height) / 2)
		*(unsigned int *)(mlx->img_addr + y * mlx->line_length + x * (mlx->bits_per_pixel / 8)) = color;
}

void	gpt_wrote_this(t_mlx *mlx)
{
	t_line	line;

	line.height = 100;
	line.x = mlx->win_width / 2;
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
	draw_line(mlx, &line);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);

}



int	map_parse(t_data *data)
{
	//this is just a test function	
	data->map = ft_split("1111111111111111111\
1000000000000000001\
1000000000000000001\
1000000000000000001\
1000000000000000001\
100000000N000000001\
1000000000000000001\
1000000000000000001\
1000000000000000001\
1111111111111111111", '\n');
	if (!data->map)
		return (-1);
	return (0);
}

int	cast_ray(t_data *data, t_mlx *mlx)
{
	
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_data	*data;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (free(mlx), 1);
	(void)argc;
	(void)argv;
	mlx->win_width = 800;
	mlx->win_height = 600;
	if (map_parse(data))
		return (1);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height, "FBI Kennedy assasination files");
	gpt_wrote_this(mlx);
	write(1, "f", 1);
	mlx_loop(mlx->mlx);
	write(1, "h", 1);
	return (0);
}