#include <stdlib.h>
#include <float.h>
#include "rt_sphere.h"

int	ray_sphere_intersect(
	const t_ray *ray,
	const t_sphere *sphere,
	float *t,
	t_intersection *inter)
{
	t_ray	r;
	t_vector3f	abc;
	float t0;
	float t1;

	r.direction = ray->direction;
	r.origin = (t_vector3f){
		ray->origin.x - sphere->centre.x,
		ray->origin.y - sphere->centre.y,
		ray->origin.z - sphere->centre.z
	};
	abc.x = v3fdot(&(r.direction), &(r.direction));
	abc.y = 2 * v3fdot(&(r.direction), &(r.origin));
	abc.z = v3fdot(&(r.origin), &(r.origin))
		- sphere->radius * sphere->radius;
	if (!quadratic(abc, &t0, &t1))
		return 0;
	if (t0 > FLT_MAX || t1 <= 0)
		return 0;
	*t = t0;
	if (*t < 0)
		*t = t1;
	t_vector3f	hit_point = {
			.x = ray->origin.x + ray->direction.x * *t,
			.y = ray->origin.y + ray->direction.y * *t,
			.z = ray->origin.z + ray->direction.z * *t,
	};
	t_vector3f	normal = {
		.x = hit_point.x - sphere->centre.x,
		.y = hit_point.y - sphere->centre.y,
		.z = hit_point.z - sphere->centre.z
	};
	normal = v3fnormalize(&normal);
	*inter = (t_intersection){
		.hit_point = hit_point,
		.normal = normal
	};
	return 1;
}

t_sphere	*new_sphere(t_vector3f centre, float radius)
{
	t_sphere	*ret;

	ret = malloc(sizeof(t_sphere));
	ret->centre = centre;
	ret->radius = radius;
	return (ret);
}

t_bounds	rt_sphere_get_bounds(t_sphere *self)
{
	t_bounds	ret;

	ret.point_max = (t_vector3f){
		self->centre.x + self->radius,
		self->centre.y + self->radius,
		self->centre.z + self->radius,
	};
	ret.point_min = (t_vector3f){
		self->centre.x - self->radius,
		self->centre.y - self->radius,
		self->centre.z - self->radius,
	};
	return (ret);
}
