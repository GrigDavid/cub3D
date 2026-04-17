#include "cub3D.h"

t_vector	sum_vector(t_vector a, t_vector b)
{
	return ((t_vector){.x = a.x + b.x, .y = a.y + b.y});
}

t_vector	sub_vector(t_vector a, t_vector b)
{
	return ((t_vector){.x = a.x - b.x, .y = a.y - b.y});
}

double	scalar_mul(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vector	mul_vector_num(t_vector a, double k)
{
	return ((t_vector){.x = a.x * k, .y = a.y * k});
}

t_vector	div_vector_num(t_vector a, double k)
{
	return ((t_vector){.x = a.x / k, .y = a.y / k});
}

void	rotate(t_vector *vector, double thetta)
{
	double old_x = vector->x;
	double old_y = vector->y;

    vector->x = old_x * cos(thetta) - old_y * sin(thetta);
    vector->y = old_x * sin(thetta) + old_y * cos(thetta);
}
