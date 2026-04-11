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
	struct timeval	time;
	t_player		*p;
	t_player		tmp;
	double			dt;
	double			speed;
	double			rot_speed;

	gettimeofday(&time, NULL);
	p = data->player;

	dt = timedif(time, data->time);
	speed = STEP * dt / 20.0;
	rot_speed = 0.05 * dt / 50.0;
	tmp = *p;

	// 🔹 forward / backward
	if (data->keypress->w)
	{
		tmp.x += p->vector.x * speed;
		tmp.y += p->vector.y * speed;
	}
	if (data->keypress->s)
	{
		tmp.x -= p->vector.x * speed;
		tmp.y -= p->vector.y * speed;
	}
	// 🔹 strafing (perpendicular to direction)
	if (data->keypress->a)
	{
		tmp.x += p->vector.y * speed;
		tmp.y -= p->vector.x * speed;
	}
	if (data->keypress->d)
	{
		tmp.x -= p->vector.y * speed;
		tmp.y += p->vector.x * speed;
	}
	/*	if (data->map[(int)(p->y / SIDE)][(int)((tmp.x - 5) / SIDE)] != '1')
		if (data->map[(int)(p->y / SIDE)][(int)((tmp.x + 5) / SIDE)] != '1')
			p->x = tmp.x;
	if (data->map[(int)((tmp.y - 5) / SIDE)][(int)(p->x / SIDE)] != '1')
		if (data->map[(int)((tmp.y + 5) / SIDE)][(int)(p->x / SIDE)] != '1')
			p->y = tmp.y;*/
	if (data->map[(int)(p->y / SIDE)][(int)(tmp.x / SIDE)] != '1')
		p->x = tmp.x;
	if (data->map[(int)(tmp.y / SIDE)][(int)(p->x / SIDE)] != '1')
		p->y = tmp.y;
	if (data->keypress->left && !data->keypress->right)
		rotate_player(p, -rot_speed);
	if (data->keypress->right && !data->keypress->left)
		rotate_player(p, rot_speed);
	data->time = time;
	draw_raypoint(data);
	mlx_put_image_to_window(data->params->mlx, data->params->win, data->params->img, 0, 0);
	return (0);
}

// int	move_square(t_data *data)
// {
// 	struct timeval	time;
// 	t_params		*p;
// 	t_player		*player;
// 	t_player		tmp;

// 	gettimeofday(&time, NULL);
// 	player = data->player;
// 	tmp.vector = player->vector;
// 	tmp.x = player->x;
// 	tmp.y = player->y;
// 	p = data->params;
// 	delete_square(10, player->x, player->y, data->params);
// 	delete_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera

// 	if (data->keypress->w)
// 	{
// 		tmp.y += STEP * player->vector.y * timedif(time, data->time) / 20;
// 		tmp.x += STEP * player->vector.x * timedif(time, data->time) / 20;
// 	}
// 	if (data->keypress->s)
// 	{
		
// 		tmp.y -= STEP * player->vector.y * timedif(time, data->time) / 20;
// 		tmp.x -= STEP * player->vector.x * timedif(time, data->time) / 20;
// 	}
// 	if (data->keypress->d)
// 	{
		
// 		tmp.x -= STEP * player->vector.y * timedif(time, data->time) / 20;
// 		tmp.y += STEP * player->vector.x * timedif(time, data->time) / 20;
// 	}
// 	if (data->keypress->a)
// 	{
// 		tmp.x += STEP * player->vector.y * timedif(time, data->time) / 20;
// 		tmp.y -= STEP * player->vector.x * timedif(time, data->time) / 20;
// 	}
// 	if (data->map[(int)(tmp.y / SIDE)][(int)(tmp.x / SIDE)] != '1')
// 	{
// 		player->x = tmp.x;
// 		player->y = tmp.y;
// 	}
	
// 	if (data->keypress->left && !data->keypress->right)
// 	{
// 		rotate_player(player, -0.05 * timedif(time, data->time) / 50);
// 	}
// 	if (data->keypress->right && !data->keypress->left)
// 	{
// 		rotate_player(player, 0.05 * timedif(time, data->time) / 50);
// 	}
	
// 	data->time = time;
// 	draw_square(10, player->x, player->y, p);
// 	draw_raypoint(data);
// 	draw_square(5, player->x + player->vector.x * 100, player->y + player->vector.y * 100, p);//camera
// 	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
// 	return (1);
// }

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
	//data is declared as global for testing purposes only. change datay to data and remove extern for .h when done
	t_data *data;

	data = malloc(sizeof(t_data *));
	(void)argc;
	(void)argv;
	if (init_data(&data))
		return (1);
	data->texture[NW] = read_texture(data, "grass.xpm");
	if (!data->texture[NW])
		return (1);//add data destruction later
	
	data->texture[SW] = read_texture(data, "jake.xpm");
	if (!data->texture[SW])
		return (1);//add data destruction later
	data->texture[EW] = read_texture(data, "texture.xpm");
	if (!data->texture[EW])
		return (1);//add data destruction later
	data->texture[SW] = read_texture(data, "chess.xpm");
	if (!data->texture[SW])
		return (1);//add data destruction later
	mlx_hook(data->params->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->params->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->params->mlx, move_square, data);
	mlx_loop(data->params->mlx);
	return (0);
}
