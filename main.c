#include "cub3D.h"

typedef struct s_pass
{
	t_player	*player;
	t_mlx		*mlx;
} t_pass;

void	draw_square(int side, int x, int y, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < side)
	{
		if (y - side / 2 + i > 0 && y - side / 2 + i < mlx->win_height && x - side / 2 > 0 && x - side / 2 < mlx->win_width)
			*(unsigned int *)(mlx->img_addr + (y - side / 2 + i) * mlx->line_length + (x - side / 2) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if (y - side / 2 + i > 0 && y - side / 2 + i < mlx->win_height && x + side / 2 > 0 && x + side / 2 < mlx->win_width)
			*(unsigned int *)(mlx->img_addr + (y - side / 2 + i) * mlx->line_length + (x + side / 2) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if (x - side / 2 + i > 0 && x - side / 2 + i < mlx->win_width && y - side / 2 > 0 && y + side / 2 < mlx->win_height)
			*(unsigned int *)(mlx->img_addr + (y - side / 2) * mlx->line_length + (x - side / 2 + i) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if (x - side / 2 + i > 0 && x - side / 2 + i < mlx->win_width && y - side / 2 > 0 && y + side / 2 < mlx->win_height)
			*(unsigned int *)(mlx->img_addr + (y + side / 2) * mlx->line_length + (x - side / 2 + i) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		i++;
	}
}

void	delete_square(int side, int x, int y, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < side)
	{
		if (y - side / 2 + i > 0 && y - side / 2 + i < mlx->win_height && x - side / 2 > 0 && x - side / 2 < mlx->win_width)
			*(unsigned int *)(mlx->img_addr + (y - side / 2 + i) * mlx->line_length + (x - side / 2) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if (y - side / 2 + i > 0 && y - side / 2 + i < mlx->win_height && x + side / 2 > 0 && x + side / 2 < mlx->win_width)
			*(unsigned int *)(mlx->img_addr + (y - side / 2 + i) * mlx->line_length + (x + side / 2) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if (x - side / 2 + i > 0 && x - side / 2 + i < mlx->win_width && y - side / 2 > 0 && y + side / 2 < mlx->win_height)
			*(unsigned int *)(mlx->img_addr + (y - side / 2) * mlx->line_length + (x - side / 2 + i) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if (x - side / 2 + i > 0 && x - side / 2 + i < mlx->win_width && y - side / 2 > 0 && y + side / 2 < mlx->win_height)
			*(unsigned int *)(mlx->img_addr + (y + side / 2) * mlx->line_length + (x - side / 2 + i) * (mlx->bits_per_pixel / 8)) = 0x000000;
		i++;
	}
}

int	move_square(t_pass *pass)
{
	t_mlx *mlx = pass->mlx;
	t_player *player = pass->player;

	printf("x: %f, y: %f\n", player->x, player->y);
	draw_square(10, player->x, player->y, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

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

	(void)line;
	line.height = 100;
	line.x = mlx->win_width / 2;
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
	//draw_line(mlx, &line);
	//draw_square(100, 200, 250, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);

}

int	move(int keycode, void *pass)
{
	t_player *player = ((t_pass *)pass)->player;

	(void)keycode;
	printf("up\n");
	delete_square(10, player->x, player->y, ((t_pass *)pass)->mlx);
	if (keycode == XK_Up)
	{
		if (player->y > 1.0)
			player->y -= 10;
	}
	else if (keycode == XK_Down)
	{
		player->y += 10;
	}
	else if (keycode == XK_Left)
		(player->x)-= 10;
	else if (keycode == XK_Right)
		(player->x) += 10;
	return (0);
}





int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_data		*data;
	t_player	player;
	t_pass		pass;

	player.vector.x = 0;
	player.vector.y = 1;
	player.x = 600;
	player.y = 250;
	pass.player = &player;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (free(mlx), 1);
	(void)argc;
	(void)argv;
	mlx->win_width = 1920;
	mlx->win_height = 1080;
	if (map_parse(data))
		return (1);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height, "cub3D");
	gpt_wrote_this(mlx);
	pass.mlx = mlx;
	mlx_hook(mlx->win, 2, KeyPressMask, move, &pass);
	mlx_hook(mlx->win, 3, KeyReleaseMask, move, &pass);
	mlx_loop_hook(mlx->mlx, move_square, &pass);
	mlx_loop(mlx->mlx);
	return (0);
}


