#include "cub3D.h"

void	draw_raypoint(t_data *data, t_vector point)
{
	draw_ray_contact(10, point.x,point.y, data->mlx);
}

int	move_square(t_data *data)
{
	t_mlx		*mlx;
	t_player	*player;

	player = data->player;
	mlx = data->mlx;
	delete_square(10, player->x, player->y, data->mlx);
	if (data->keypress->w && data->map[((int)player->x) / SIDE][((int)player->y - STEP) / SIDE] == '0')
		player->y -= STEP;
	if (data->keypress->s && data->map[((int)player->x) / SIDE][((int)player->y + STEP) / SIDE] == '0')
		player->y += STEP;
	if (data->keypress->a && data->map[((int)player->x - STEP) / SIDE][((int)player->y) / SIDE] == '0')
		player->x -= STEP;
	if (data->keypress->d && data->map[((int)player->x + STEP) / SIDE][((int)player->y) / SIDE] == '0')
		player->x += STEP;
	draw_square(10, player->x, player->y, mlx);
	// draw_raypoint(data, cast_ray(data->player, data->map));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		exit(0);
	}
	if (keycode == XK_w)
	{
		data->keypress->w = 1;
	}
	else if (keycode == XK_s)
	{
		data->keypress->s = 1;
	}
	else if (keycode == XK_a)
	{
		data->keypress->a = 1;
	}
	else if (keycode == XK_d)
	{
		data->keypress->d = 1;
	}
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
	{
		data->keypress->w = 0;
	}
	else if (keycode == XK_s)
	{
		data->keypress->s = 0;
	}
	else if (keycode == XK_a)
	{
		data->keypress->a = 0;
	}
	else if (keycode == XK_d)
	{
		data->keypress->d = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	if (init_data(&data))
		return (1);
	draw_walls(data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->mlx->mlx, move_square, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
