#include	"cub3D.h"

void	draw_walls(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->configs->map->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				draw_square(SIDE, j * SIDE + SIDE / 2, i * SIDE + SIDE / 2, data->params);
			}
			j++;
		}
		i++;
	}
	
}