#include "cub3D.h"

void	draw_square(int side, int x, int y, t_params *p)
{
	int	i;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	i = 0;
	x1 = x - side / 2;
	y1 = y - side / 2;
	x2 = x + side / 2;
	y2 = y + side / 2;
	while (i < side)
	{
		if ((x1 + i > 0 && x1 + i < p->win_width) && (y1 > 0 && y1 < p->win_height))
			*(unsigned int *)(p->img_addr + (y1) * p->line_length + (x1 + i) * (p->bits_per_pixel / 8)) = 0xffffff;
		if ((x1 > 0 && x1 < p->win_width) && (y1 + i > 0 && y1 + i < p->win_height))
			*(unsigned int *)(p->img_addr + (y1 + i) * p->line_length + (x1) * (p->bits_per_pixel / 8)) = 0xffffff;
		if ((x2 - i > 0 && x2- i < p->win_width) && (y2 > 0 && y2 < p->win_height))
			*(unsigned int *)(p->img_addr + (y2) * p->line_length + (x2 - i) * (p->bits_per_pixel / 8)) = 0xffffff;
		if ((x2 > 0 && x2 < p->win_width) && (y2 - i > 0 && y2 - i < p->win_height))
			*(unsigned int *)(p->img_addr + (y2 - i) * p->line_length + (x2) * (p->bits_per_pixel / 8)) = 0xffffff;
		i++;
	}
}

void	draw_ray_contact(int side, int x, int y, t_params *p)
{
	int	i;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	i = 0;
	x1 = x - side / 2;
	y1 = y - side / 2;
	x2 = x + side / 2;
	y2 = y + side / 2;
	while (i < side)
	{
		if ((x1 + i > 0 && x1 + i < p->win_width) && (y1 > 0 && y1 < p->win_height))
			*(unsigned int *)(p->img_addr + (y1) * p->line_length + (x1 + i) * (p->bits_per_pixel / 8)) = 0xff0000;
		if ((x1 > 0 && x1 < p->win_width) && (y1 + i > 0 && y1 + i < p->win_height))
			*(unsigned int *)(p->img_addr + (y1 + i) * p->line_length + (x1) * (p->bits_per_pixel / 8)) = 0xff0000;
		if ((x2 - i > 0 && x2- i < p->win_width) && (y2 > 0 && y2 < p->win_height))
			*(unsigned int *)(p->img_addr + (y2) * p->line_length + (x2 - i) * (p->bits_per_pixel / 8)) = 0xff0000;
		if ((x2 > 0 && x2 < p->win_width) && (y2 - i > 0 && y2 - i < p->win_height))
			*(unsigned int *)(p->img_addr + (y2 - i) * p->line_length + (x2) * (p->bits_per_pixel / 8)) = 0xff0000;

		if ((x + i > 0 && x + i < p->win_width) && (y1 > 0 && y1 < p->win_height))
			*(unsigned int *)(p->img_addr + (y1) * p->line_length + (x + i) * (p->bits_per_pixel / 8)) = 0xff0000;
		if ((x1 > 0 && x1 < p->win_width) && (y + i > 0 && y + i < p->win_height))
			*(unsigned int *)(p->img_addr + (y + i) * p->line_length + (x1) * (p->bits_per_pixel / 8)) = 0xff0000;
		
		i++;
	}
}

void	delete_square(int side, int x, int y, t_params *p)
{
	int	i;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	i = 0;
	x1 = x - side / 2;
	y1 = y - side / 2;
	x2 = x + side / 2;
	y2 = y + side / 2;
	while (i < side)
	{
		if ((x1 + i > 0 && x1 + i < p->win_width) && (y1 > 0 && y1 < p->win_height))
			*(unsigned int *)(p->img_addr + (y1) * p->line_length + (x1 + i) * (p->bits_per_pixel / 8)) = 0x000000;
		if ((x1 > 0 && x1 < p->win_width) && (y1 + i > 0 && y1 + i < p->win_height))
			*(unsigned int *)(p->img_addr + (y1 + i) * p->line_length + (x1) * (p->bits_per_pixel / 8)) = 0x000000;
		if ((x2 - i > 0 && x2- i < p->win_width) && (y2 > 0 && y2 < p->win_height))
			*(unsigned int *)(p->img_addr + (y2) * p->line_length + (x2 - i) * (p->bits_per_pixel / 8)) = 0x000000;
		if ((x2 > 0 && x2 < p->win_width) && (y2 - i > 0 && y2 - i < p->win_height))
			*(unsigned int *)(p->img_addr + (y2 - i) * p->line_length + (x2) * (p->bits_per_pixel / 8)) = 0x000000;
		i++;
	}
}

unsigned int	*get_pixel(int x, int y, t_params *p)
{
	return ((unsigned int *)(p->img_addr + y * p->line_length + x * (p->bits_per_pixel / 8)));
}
unsigned int	*get_txt_pixel(int x, int y, t_texture *p)
{
	return ((unsigned int *)(p->addr + y * p->line_length + x * (p->bits_per_pixel / 8)));
}

int	get_texture_x(t_data *data, t_point p)
{
	double local;
double wall_x;

if (p.x - floor(p.x) < p.y - floor(p.y)) // vertical wall
    local = fmod(p.y, 100.0);
else
    local = fmod(p.x, 100.0);

wall_x = local / 100.0;
return((int)(wall_x * data->texture->width));
}

void	draw_texture(t_data *data, t_line line, t_point p)
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
	txt_x = get_texture_x(data, p);
	// txt_x = (int)p.y % data->texture->width;
	// if (p.x == ceil(p.x))
	// 	txt_x = (int)p.x % data->texture->width;
	step = (double)data->texture->height / (double)line.height;
	txt_y = 0;
	if (line.height > data->params->win_height)
		txt_y = (line.height - data->params->win_height) / 2;
	while (y < pr->win_height && txt_y < data->texture->height)
	{
		*(unsigned int *)get_pixel(line.x, y, data->params) = *(unsigned int *)get_txt_pixel(txt_x, (int)txt_y, data->texture);
		y++;
		txt_y += step;
	}
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
		*(unsigned int *)(pr->img_addr + i++ * pr->line_length + x * (pr->bits_per_pixel / 8)) = 0x444444;
	draw_texture(data, line, p);
	y = (pr->win_height + height) / 2;
	while (y < pr->win_height)
		*(unsigned int *)(pr->img_addr + y++ * pr->line_length + x * (pr->bits_per_pixel / 8)) = 0x222222;
}
