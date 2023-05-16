#include "rt_cylinder.h"
#include "rt_ray.h"
#include "rt_plane.h"

int	ray_cylinder_side(
	const t_ray *ray,
	const t_cylinder *cy,
	float t,
	t_intersection *inter
)
{
	t_vector3f		x;
	t_vector3f		magnitude;

	x = v3fsub(&ray->origin, &cy->centre);
	magnitude.x = v3fdot(&ray->direction, &cy->normal)
		* t + v3fdot(&x, &cy->normal);
	if (magnitude.x < 0 || magnitude.x > cy->height)
		return (0);
	inter->hit_point = mul_v3fs1f(&ray->direction, t);
	inter->hit_point = v3fadd(&ray->origin, &inter->hit_point);
	inter->normal = mul_v3fs1f(&cy->normal, -magnitude.x);
	inter->normal = v3fadd(&(inter->normal), &(inter->hit_point));
	inter->normal = v3fsub(&(inter->normal), &cy->centre);
	inter->normal = v3fnormalize(&(inter->normal));
	return (1);
}

int	ray_cyliner_far_base(
	const t_ray *ray,
	const t_cylinder *cy,
	float *t,
	t_intersection *inter
)
{
	t_plane		plane;
	t_vector3f	tmp;

	plane.normal = cy->normal;
	tmp = mul_v3fs1f(&cy->normal, cy->height);
	if (v3fdot(&ray->direction, &cy->normal) <= 0)
		plane.centre = cy->centre;
	else
		plane.centre = v3fadd(&cy->centre, &tmp);
	ray_plane_intersect(ray, &plane, t, inter);
	if (ray_plane_intersect(ray, &plane, t, inter))
	{
		tmp = v3fsub(&inter->hit_point, &(plane.centre));
		if (v3fsize(&tmp) < cy->diameter)
			return (1);
	}
	return (0);
}

int	ray_cyliner_near_base(
	const t_ray *ray,
	const t_cylinder *cy,
	float *t,
	t_intersection *inter
)
{
	t_plane		plane;
	t_vector3f	tmp;

	plane.normal = cy->normal;
	tmp = mul_v3fs1f(&cy->normal, cy->height);
	if (v3fdot(&ray->direction, &cy->normal) > 0)
		plane.centre = cy->centre;
	else
		plane.centre = v3fadd(&cy->centre, &tmp);
	if (ray_plane_intersect(ray, &plane, t, inter))
	{
		tmp = v3fsub(&inter->hit_point, &(plane.centre));
		if (v3fsize(&tmp) < cy->diameter)
			return (1);
	}
	return (0);
}

int	ray_cylinder_relay(
	const t_ray *ray,
	const t_cylinder *cy,
	t_vector3f *t,
	t_intersection *inter
)
{
	if (ray_cyliner_near_base(ray, cy, &t->z, inter))
		return (1);
	t->z = t->x;
	if (ray->min_t <= t->x && t->x < ray->max_t
		&& ray_cylinder_side(ray, cy, t->x, inter))
		return (1);
	if (ray_cyliner_far_base(ray, cy, &t->z, inter))
		return (1);
	t->z = t->y;
	if (ray->min_t <= t->y && t->y < ray->max_t
		&& ray_cylinder_side(ray, cy, t->y, inter))
	{
		inter->normal = v3fnag(&inter->normal);
		return (1);
	}
	return (0);
}

int	ray_cylinder_intersect(
	const t_ray *ray,
	const t_cylinder *cy,
	float *t,
	t_intersection *inter
)
{
	t_vector3f	x;
	t_vector3f	abc;
	t_vector3f	magnitude;
	int			ret;

	x = v3fsub(&ray->origin, &cy->centre);
	abc.x = v3fdot(&ray->direction, &ray->direction)
		- powf(v3fdot(&ray->direction, &cy->normal), 2.0);
	abc.y = 2 * (v3fdot(&ray->direction, &x)
			- v3fdot(&ray->direction, &cy->normal) * v3fdot(&x, &cy->normal));
	abc.z = v3fdot(&x, &x) - powf(v3fdot(&x, &cy->normal), 2)
		- (cy->diameter * cy->diameter);
	if (!quadratic(abc, &(magnitude.x), &(magnitude.y)))
		return (0);
	ret = ray_cylinder_relay(ray, cy, &magnitude, inter);
	*t = magnitude.z;
	return (ret);
}