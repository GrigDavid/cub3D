#include "cub3D.h"

static long long	my_time(struct timeval tmp)
{
	long long	res;

	res = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return (res);
}

long long	timedif(struct timeval t1, struct timeval t2)
{
	return (my_time(t1) - my_time(t2));
}