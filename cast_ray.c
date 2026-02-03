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
	int	delta_x;
	int	delta_y;

	x = 1;
	y = 1;
	while (1)
	{
		if (square_sum(player->vector.x + (float)x), get_cor(player, x) < square_sum(get_cor(player, y), player->vector.y + (float)y))
		{
			//check with x
			if (map[])
		}
		else
		{
			//check with y
		}
	}
}

int	cast_ray(t_player	*player, char	**map)
{
	return (get_len(t_player	*player, char	**map));
}