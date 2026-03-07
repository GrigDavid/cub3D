#include "cub3D.h"

void	rotate(t_vector *vector, double thetta)
{
	double old_x = vector->x;
	double old_y = vector->y;

    vector->x = old_x * cos(thetta) - old_y * sin(thetta);
    vector->y = old_x * sin(thetta) + old_y * cos(thetta);
}

void	imcameraaxper(t_player *player, )
{

}