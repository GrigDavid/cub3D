#include "cub3D.h"

void	draw_square(int side, int x, int y, t_mlx *mlx)
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
		if ((x1 + i > 0 && x1 + i < mlx->win_width) && (y1 > 0 && y1 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1) * mlx->line_length + (x1 + i) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if ((x1 > 0 && x1 < mlx->win_width) && (y1 + i > 0 && y1 + i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1 + i) * mlx->line_length + (x1) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if ((x2 - i > 0 && x2- i < mlx->win_width) && (y2 > 0 && y2 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2) * mlx->line_length + (x2 - i) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		if ((x2 > 0 && x2 < mlx->win_width) && (y2 - i > 0 && y2 - i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2 - i) * mlx->line_length + (x2) * (mlx->bits_per_pixel / 8)) = 0xffffff;
		i++;
	}
}

void	draw_ray_contact(int side, int x, int y, t_mlx *mlx)
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
		if ((x1 + i > 0 && x1 + i < mlx->win_width) && (y1 > 0 && y1 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1) * mlx->line_length + (x1 + i) * (mlx->bits_per_pixel / 8)) = 0xff0000;
		if ((x1 > 0 && x1 < mlx->win_width) && (y1 + i > 0 && y1 + i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1 + i) * mlx->line_length + (x1) * (mlx->bits_per_pixel / 8)) = 0xff0000;
		if ((x2 - i > 0 && x2- i < mlx->win_width) && (y2 > 0 && y2 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2) * mlx->line_length + (x2 - i) * (mlx->bits_per_pixel / 8)) = 0xff0000;
		if ((x2 > 0 && x2 < mlx->win_width) && (y2 - i > 0 && y2 - i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2 - i) * mlx->line_length + (x2) * (mlx->bits_per_pixel / 8)) = 0xff0000;

		if ((x + i > 0 && x + i < mlx->win_width) && (y1 > 0 && y1 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1) * mlx->line_length + (x + i) * (mlx->bits_per_pixel / 8)) = 0xff0000;
		if ((x1 > 0 && x1 < mlx->win_width) && (y + i > 0 && y + i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y + i) * mlx->line_length + (x1) * (mlx->bits_per_pixel / 8)) = 0xff0000;
		
		i++;
	}
}

void	delete_square(int side, int x, int y, t_mlx *mlx)
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
		if ((x1 + i > 0 && x1 + i < mlx->win_width) && (y1 > 0 && y1 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1) * mlx->line_length + (x1 + i) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if ((x1 > 0 && x1 < mlx->win_width) && (y1 + i > 0 && y1 + i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y1 + i) * mlx->line_length + (x1) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if ((x2 - i > 0 && x2- i < mlx->win_width) && (y2 > 0 && y2 < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2) * mlx->line_length + (x2 - i) * (mlx->bits_per_pixel / 8)) = 0x000000;
		if ((x2 > 0 && x2 < mlx->win_width) && (y2 - i > 0 && y2 - i < mlx->win_height))
			*(unsigned int *)(mlx->img_addr + (y2 - i) * mlx->line_length + (x2) * (mlx->bits_per_pixel / 8)) = 0x000000;
		i++;
	}
}

void	draw_line(t_mlx *mlx, t_line *line)
{
	int	height;
	int	x;
	int	y;
	int	color;

	x = line->x;
	if (x < 0 || x >= mlx->win_width)
		return ;
	height = line->height;
	if (height >= mlx->win_height)
		height = mlx->win_height;
	y = (mlx->win_height - line->height) / 2;
	color = 0x00eaff;
	while (y++ < (mlx->win_height + line->height) / 2)
		*(unsigned int *)(mlx->img_addr + y * mlx->line_length + x * (mlx->bits_per_pixel / 8)) = color;
}
