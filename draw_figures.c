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

void	draw_line(t_params *p, t_line *line)
{
	int	height;
	int	x;
	int	y;
	int	color;

	x = line->x;
	if (x < 0 || x >= p->win_width)
		return ;
	height = line->height;
	if (height >= p->win_height)
		height = p->win_height;
	y = (p->win_height - line->height) / 2;
	color = 0x00eaff;
	while (y++ < (p->win_height + line->height) / 2)
		*(unsigned int *)(p->img_addr + y * p->line_length + x * (p->bits_per_pixel / 8)) = color;
}

//void	draw_line_ab(t_mlx *mlx, t_vector *a, t_vector *b)
//{

//}
