//https://youtu.be/NbSee-XM7WA?si=nx_mxe-1iqoI4h1p
//https://lodev.org/cgtutor/raycasting.html

#include "cub3D.h"

void	draw_raypoint(t_data *data)
{
	// t_point	p = dda(*(data->player), data->map);
	// draw_square(10, p.x, p.y, data->params);
	imcameraaxper(data, data->map);
}

void	rotate_player(t_player *player, double thetta)
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
	t_player	tmp;


	player = data->player;
	tmp.vector = player->vector;
	tmp.x = player->x;
	tmp.y = player->y;
	p = data->params;
	delete_square(10, player->x, player->y, data->params);
	delete_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera

	if (data->keypress->w)
	{
		tmp.y += STEP * player->vector.y;
		tmp.x += STEP * player->vector.x;
	}
	if (data->keypress->s)
	{
		
		tmp.y -= STEP * player->vector.y;
		tmp.x -= STEP * player->vector.x;
	}
	if (data->keypress->d)
	{
		
		tmp.x -= STEP * player->vector.y;
		tmp.y += STEP * player->vector.x;
	}
	if (data->keypress->a)
	{
		tmp.x += STEP * player->vector.y;
		tmp.y -= STEP * player->vector.x;
	}
	if (data->map[(int)(tmp.y / SIDE)][(int)(tmp.x / SIDE)] != '1')
	{
		player->x = tmp.x;
		player->y = tmp.y;
	}
	
	if (data->keypress->left && !data->keypress->right)
	{
		rotate_player(player, -0.05);
	}
	if (data->keypress->right && !data->keypress->left)
	{
		rotate_player(player, 0.05);
	}
	

	// draw_square(10, player->x, player->y, p);
	draw_raypoint(data);
	// draw_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera
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
t_data ** datay;
int	main(int argc, char **argv)
{
	//data is declared as global for testing purposes only. change datay to data and remove extern for .h when done
	//t_data *data;

	datay = malloc(sizeof(t_data *));
	(void)argc;
	(void)argv;
	if (init_data(datay))
		return (1);
	// write(1, "hasa\n", 5);
	draw_walls(*datay);
	printf("vector y : %f\n", (*datay)->player->vector.y);
	mlx_hook((*datay)->params->win, KeyPress, KeyPressMask, key_press, *datay);
	mlx_hook((*datay)->params->win, KeyRelease, KeyReleaseMask, key_release, *datay);
	mlx_loop_hook((*datay)->params->mlx, move_square, *datay);
	mlx_loop((*datay)->params->mlx);
	return (0);
}
