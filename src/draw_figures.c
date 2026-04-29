#include "../includes/cub3D.h"/////

unsigned int	*get_pixel(int x, int y, t_params *p)
{
	return ((unsigned int *)(p->img_addr + y * p->line_length + x * (p->bits_per_pixel / 8)));
}
unsigned int	*get_txt_pixel(int x, int y, t_texture *p)
{
	return ((unsigned int *)(p->addr + y * p->line_length + x * (p->bits_per_pixel / 8)));
}

int	get_texture_x(t_texture *txt, t_point p)
{
	double	local;
	double	wall_x;

	if (p.x - floor(p.x) < p.y - floor(p.y))
		local = fmod(p.y, 100.0);
	else
		local = fmod(p.x, 100.0);
	wall_x = local / 100.0;
	return((int)(wall_x * txt->width));
}

void	draw_texture(t_data *data, t_line line, t_point p, t_texture *txt)
{
	int			y;
	int			txt_x;
	t_params	*pr;
	double		step;
	double		txt_y;

	pr = data->params;
	y = (pr->win_height - line.height) / 2;
	if (line.height > data->params->win_height)
		y = 0;
	txt_x = get_texture_x(txt, p);
	step = (double)txt->height / (double)line.height;
	txt_y = 0;
	if (line.height > data->params->win_height)
		txt_y = (line.height - data->params->win_height) * step / 2;
	while (y < pr->win_height && txt_y < txt->height)
	{
		*(unsigned int *)get_pixel(line.x, y, data->params) = *(unsigned int *)get_txt_pixel(txt_x, (int)txt_y, txt);
		y++;
		txt_y += step;
	}
}

int	txt_side(t_player *player, t_point p)
{
	if (fabs(p.x - floor(p.x)) < 0.00000001 || fabs(p.x - ceil(p.x)) < 0.00000001)
	{
		if (player->x > p.x)
			return (WW);
		return (EW);
	}
	if (player->y > p.y)
		return (SW);
	return (NW);
}

void	draw_vert_line(t_data *data, t_line line, t_point p)
{
	int			height;
	t_params	*pr;
	int			x;
	int			y;

	pr = data->params;
	x = line.x;
	if (x < 0 || x >= pr->win_width)
		return ;
	height = line.height;
	if (height >= pr->win_height)
		height = pr->win_height;
	y = (pr->win_height - height) / 2;
	int	i = 0;
	while (i < y)
		*(unsigned int *)(pr->img_addr + i++ * pr->line_length + x * (pr->bits_per_pixel / 8)) = data->configs->c;
	draw_texture(data, line, p, data->texture[txt_side(data->player, p)]);
	y = (pr->win_height + height) / 2;
	while (y < pr->win_height)
		*(unsigned int *)(pr->img_addr + y++ * pr->line_length + x * (pr->bits_per_pixel / 8)) = data->configs->f;
}
