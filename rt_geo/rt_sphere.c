#include <stdlib.h>
#include <float.h>
#include "rt_sphere.h"

int	ray_sphere_intersect(const t_ray *ray, const t_sphere *sphere, float *t)
{
	t_ray	r;

	r.direction = ray->direction;
	r.origin = (t_vector3f){
		ray->origin.x - sphere->centre.x,
		ray->origin.y - sphere->centre.y,
		ray->origin.z - sphere->centre.z
	};

	float a = r.direction.x * r.direction.x
		+ r.direction.y * r.direction.y
		+ r.direction.z * r.direction.z;
	float b = 2 * (r.direction.x * r.origin.x
		+ r.direction.y * r.origin.y
		+ r.direction.z * r.origin.z);
	float c = r.origin.x * r.origin.x
		+ r.origin.y * r.origin.y
		+ r.origin.z * r.origin.z
		- sphere->radius * sphere->radius;
	float t0;
	float t1;
	if (!quadratic((t_vector3f){a, b, c}, &t0, &t1))
		return 0;
	if (t0 > FLT_MAX || t1 <= 0)
		return 0;
	*t = t0;
	if (*t < 0)
		*t = t1;
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
