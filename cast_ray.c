#include	"cub3D.h"


float	square_sum(float a, float b)
{
	return (a * a + b * b);
}

t_vector	mul_vector(t_vector vector, float k)
{
	vector.x = vector.x * k;
	vector.y = vector.y * k;
	return (vector);
}

float	get_cor(t_player *player, int x)
{
	float	delta_x;
	t_vector	tmp;

	delta_x = x - (player->x - (float)(int)(player->x));
	tmp.x = player->vector.x;
	tmp.y = player->vector.y;
	return(mul_vector(tmp, delta_x).y);
}


int	get_len(t_player	*player, char	**map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (1)
	{
		if (square_sum(player->vector.x + (float)x, get_cor(player, x)) < square_sum(get_cor(player, y), player->vector.y + (float)y))
		{
			//check with x
			if (map[(int)(player->vector.x + (float)x)][(int)get_cor(player, x)] == 1 || map[(int)(player->vector.x + (float)x)][(int)get_cor(player, x) - 1] == 1)
				return (square_sum(player->vector.x + (float)x, get_cor(player, x)));
			x++;
		}
		else
		{
			if (map[(int)get_cor(player, y)][(int)(player->vector.y + (float)y)] == 1 || map[(int)get_cor(player, y) - 1][(int)(player->vector.y + (float)y)] == 1)
				return ((int)square_sum(player->vector.x + (float)x, (int)get_cor(player, x)));
		}
	}
}

int	cast_ray(t_player	*player, char	**map)
{
	return (get_len(player, map));
}
