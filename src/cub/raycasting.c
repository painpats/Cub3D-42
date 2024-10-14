#include "../../inc/cub.h"

static double	resolution_distance(double xx, double yy)
{
	if (fabs(xx) == 0)
		return (fabs(yy) + 0.000001);
	else if (fabs(yy) == 0)
		return (fabs(xx) + 0.000001);
	else if (fabs(xx) < fabs(yy))
		return (fabs(xx) + 0.000001);
	else
		return (fabs(yy) + 0.000001);
}

void	ray_casting(double *ray_len, double x, double y, double a)
{
	double	xx;
	double	yy;

	if ((a > 0 && a <= M_PI_2) || (a > 0 + 2 * M_PI && a <= M_PI_2 + 2 * M_PI))
	{
		xx = (((int)x - x + 1) / cos(a));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a > M_PI_2 && a < M_PI)
	{
		xx = (x - (int)x) / (cos(correct_angle(a)));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a <= -M_PI_2 + 2 * M_PI && a >= M_PI)
	{
		xx = (x - (int)x) / (cos(correct_angle(a)));
		yy = (y - (int)y) / (sin(correct_angle(a)));
	}
	else
	{
		xx = ((int)x - x + 1) / cos(a);
		yy = (y - (int)y) / (sin(correct_angle(a)));
	}
	*ray_len = *ray_len + resolution_distance(xx, yy);
}
