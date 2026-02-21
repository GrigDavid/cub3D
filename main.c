//https://youtu.be/NbSee-XM7WA?si=nx_mxe-1iqoI4h1p
//https://lodev.org/cgtutor/raycasting.html

#include "cub3D.h"

void	draw_raypoint(t_data *data)
{
	t_point	p = dda(*(data->player), data->map);
	draw_square(10, p.x, p.y, data->params);
}

void	rotate(t_player *player, double thetta)
{
	double old_x = player->vector.x;
	double old_y = player->vector.y;

    player->vector.x = old_x * cos(thetta) - old_y * sin(thetta);
    player->vector.y = old_x * sin(thetta) + old_y * cos(thetta);
}

int	move_square(t_data *data)
{
	t_params	*p;
	t_player	*player;

	player = data->player;
	p = data->params;
	delete_square(10, player->x, player->y, data->params);
	delete_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera
	if (data->keypress->w && data->map[((int)player->y - STEP) / SIDE][((int)player->x) / SIDE] != '1')
		player->y -= STEP;
	if (data->keypress->s && data->map[((int)player->y + STEP) / SIDE][((int)player->x) / SIDE] != '1')
		player->y += STEP;
	if (data->keypress->a && data->map[((int)player->y) / SIDE][((int)player->x - STEP) / SIDE] != '1')
		player->x -= STEP;
	if (data->keypress->d && data->map[((int)player->y) / SIDE][((int)player->x + STEP) / SIDE] != '1')
		player->x += STEP;
	if (data->keypress->left && !data->keypress->right)
	{
		rotate(player, -0.01);
	}
	if (data->keypress->right && !data->keypress->left)
	{
		rotate(player, 0.01);
	}
	draw_square(10, player->x, player->y, p);
	//draw_raypoint(data);
	draw_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
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
	else if (keycode == XK_Left)
	{
		data->keypress->left = 1;
	}
	else if (keycode == XK_Right)
	{
		data->keypress->right = 1;
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
	else if (keycode == XK_Left)
	{
		data->keypress->left = 0;
	}
	else if (keycode == XK_Right)
	{
		data->keypress->right = 0;
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
	mlx_hook(data->params->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->params->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->params->mlx, move_square, data);
	mlx_loop(data->params->mlx);
	return (0);
}
