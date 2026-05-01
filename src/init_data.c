#include "cub3D.h"

// int	map_parse(t_data *data)
// {
// 	//this is just a test function	
// 	data->map = ft_split("1111111111111111111;
// 1000000000000000001;
// 1000000000000000001;
// 1000000000000100001;
// 1000000000000100001;
// 100000000N000100001;
// 1000000000000100001;
// 1000000001111100001;
// 1000000000000000001;
// 1111111111111111111", ';');
// 	data->params->win_height = 1080;
// 	data->params->win_width = 1920;
// 	if (!data->map)
// 		return (-1);
// 	return (0);
// }

int	init_keypress(t_data *data)
{
	data->keypress = (t_keypress *)malloc(sizeof(t_keypress));
	if (!data->keypress)
		return (1);
	data->keypress->w = 0;
	data->keypress->a = 0;
	data->keypress->s = 0;
	data->keypress->d = 0;
	data->keypress->left = 0;
	data->keypress->right = 0;
	return (0);
}

int	init_data(t_data **data)
{//BEWARE: malloc protections are almost non-existant	:)
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (1);
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	if (!(*data)->player)
		return (free(*data), 1);
	if (init_keypress(*data))
		return (free((*data)->player), free(*data), 1);
	(*data)->player->x = 2750;
	(*data)->player->y = 350;
	(*data)->player->vector.x = 0;
	(*data)->player->vector.y = 1;
	(*data)->params = (t_params *)malloc(sizeof(t_params));
	if (!((*data)->params))
		return (free((*data)->player), free(*data), 1);
	// if (map_parse(*data))
	// 	return (1);//
	(*data)->params->win_height = 1080;
	(*data)->params->win_width = 1920;
	(*data)->params->mlx = mlx_init();
	if (!(*data)->params->mlx)
		return (free((*data)->params), free((*data)->player), free(*data), 1);
	//these 3 lines no need malloc prot?
	(*data)->params->win = mlx_new_window((*data)->params->mlx, (*data)->params->win_width, (*data)->params->win_height, "cub3D");
	(*data)->params->img = mlx_new_image((*data)->params->mlx, (*data)->params->win_width, (*data)->params->win_height);
	(*data)->params->img_addr = mlx_get_data_addr((*data)->params->img, &((*data)->params->bits_per_pixel), &((*data)->params->line_length), &((*data)->params->endian));
	//these 3 lines no need malloc prot?
	gettimeofday(&(*data)->time, NULL);
	return (0);
}
