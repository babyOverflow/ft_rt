#include <math.h>
#include "rt_geo.h"

#define normLN

int	rt_cond_swap_float(int c, float *a, float *b)
{
	float	tmp;

	if (c)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		return c;
	}
	return c;
}

inline int	rt_bounds_ray_intersect_x(
	const t_bounds *b,
	const t_ray *r,
	float *t0,
	float *t1
)
{
	float	near;
	float	far;
	float	inv;

	inv = 1 / r->direction.x;
	near = (b->point_min.x - r->origin.x) * inv;
	far = (b->point_max.x - r->origin.x) * inv;
	rt_cond_swap_float(near > far, &near, &far);
	rt_cond_swap_float(near > *t0, &near, t0);
	rt_cond_swap_float(far < *t1, &far, t1);
	if (*t0 > *t1)
		return 0;
	else
		return 1;
}

inline int	rt_bounds_ray_intersect_y(
	const t_bounds *b,
	const t_ray *r,
	float *t0,
	float *t1
)
{
	float	near;
	float	far;
	float	inv;

	inv = 1 / r->direction.y;
	near = (b->point_min.y - r->origin.y) * inv;
	far = (b->point_max.y - r->origin.y) * inv;
	rt_cond_swap_float(near > far, &near, &far);
	rt_cond_swap_float(near > *t0, &near, t0);
	rt_cond_swap_float(far < *t1, &far, t1);
	if (*t0 > *t1)
		return 0;
	else
		return 1;
}

inline int	rt_bounds_ray_intersect_z(
	const t_bounds *b,
	const t_ray *r,
	float *t0,
	float *t1
)
{
	float	near;
	float	far;
	float	inv;

	inv = 1 / r->direction.z;
	near = (b->point_min.z - r->origin.z) * inv;
	far = (b->point_max.z - r->origin.z) * inv;
	rt_cond_swap_float(near > far, &near, &far);
	rt_cond_swap_float(near > *t0, &near, t0);
	rt_cond_swap_float(far < *t1, &far, t1);
	if (*t0 > *t1)
		return 0;
	else
		return 1;
}

int	rt_bounds_ray_intersect(t_bounds *b, t_ray *r)
{
	float	inv;
	float	t0;
	float	t1;

	t0 = NAN;
	t1 = INFINITY;
	rt_bounds_ray_intersect_x(b, r, &t0, &t1);
	rt_bounds_ray_intersect_y(b, r, &t0, &t1);
	if (t0 > t1)
		return 0;
	rt_bounds_ray_intersect_z(b, r, &t0, &t1);
	if (t0 > t1)
		return 0;
	return 1;
}
