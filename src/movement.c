/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:08:20 by rababaya          #+#    #+#             */
/*   Updated: 2026/05/04 19:01:32 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_player *player, double thetta)
{
	double	old_x;
	double	old_y;

	old_x = player->vector.x;
	old_y = player->vector.y;
	player->vector.x = old_x * cos(thetta) - old_y * sin(thetta);
	player->vector.y = old_x * sin(thetta) + old_y * cos(thetta);
}

void	set_wasd(t_data *data, t_player tmp)
{
	if (data->configs->map->map[(int)(data->player->y / SIDE)]
			[(int)(tmp.x / SIDE)] != '1')
		data->player->x = tmp.x;
	if (data->configs->map->map[(int)(tmp.y / SIDE)]
			[(int)(data->player->x / SIDE)] != '1')
		data->player->y = tmp.y;
}

void	check_wasd(t_data *data, double speed)
{
	t_player	tmp;

	tmp = *(data->player);
	if (data->keypress->w)
	{
		tmp.x += data->player->vector.x * speed;
		tmp.y += data->player->vector.y * speed;
	}
	if (data->keypress->s)
	{
		tmp.x -= data->player->vector.x * speed;
		tmp.y -= data->player->vector.y * speed;
	}
	if (data->keypress->a)
	{
		tmp.x += data->player->vector.y * speed * 0.5;
		tmp.y -= data->player->vector.x * speed * 0.5;
	}
	if (data->keypress->d)
	{
		tmp.x -= data->player->vector.y * speed;
		tmp.y += data->player->vector.x * speed;
	}
	set_wasd(data, tmp);
}

int	movement(t_data *data)
{
	struct timeval	time;
	t_player		*p;
	double			dt;
	double			speed;
	double			rot_speed;

	gettimeofday(&time, NULL);
	p = data->player;
	dt = timedif(time, data->time);
	speed = STEP * dt / 20.0;
	rot_speed = 0.05 * dt / 50.0;
	check_wasd(data, speed);
	if (data->keypress->left && !data->keypress->right)
		rotate_player(p, -rot_speed);
	if (data->keypress->right && !data->keypress->left)
		rotate_player(p, rot_speed);
	data->time = time;
	imcameraaxper(data, data->configs->map->map);
	mlx_put_image_to_window(data->params->mlx, data->params->win,
		data->params->img, 0, 0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_game(data);
	if (keycode == XK_w)
		data->keypress->w = 1;
	else if (keycode == XK_s)
		data->keypress->s = 1;
	else if (keycode == XK_a)
		data->keypress->a = 1;
	else if (keycode == XK_d)
		data->keypress->d = 1;
	else if (keycode == XK_Left)
		data->keypress->left = 1;
	else if (keycode == XK_Right)
		data->keypress->right = 1;
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

int	close_game(t_data *data)
{
	free_data(data);
	exit (0);
}
