#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "rt_bounds.h"
#include "rt_cylinder.h"
#include "rt_ray.h"
#include "rt_plane.h"

t_cylinder	*new_cylinder(
	t_vector3f centre,
	t_vector3f normal,
	float height,
	float diameter
)
{
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	ret->centre = centre;
	ret->normal = v3fnormalize(&normal);
	ret->height = height;
	ret->diameter = diameter;
	return (ret);
}

int	ray_cylinder_intersect_relay2(
	const t_ray *ray,
	const t_cylinder *cy,
	t_vector3f *magnitude,
	t_intersection *inter
)
{
	t_plane		plane;
	float		t;
	const float	m0 = magnitude->x;
	const float	m1 = magnitude->y;

	if (m0 < 0 && m1 > 0)
		plane = (t_plane){
			.centre = cy->centre,
			.normal = v3fnag(&cy->normal)
		};
	else if (m0 > cy->height && m1 < cy->height)
		plane = (t_plane){
			.centre = v3fadd(&cy->centre, &(t_vector3f){
				.x = cy->normal.x * cy->height,
				.y = cy->normal.y * cy->height,
				.z = cy->normal.z * cy->height,
			}),
			.normal = cy->normal
		};
	else
		return (0);
	return ray_plane_intersect(ray, &plane, &(magnitude->z), inter);
}

int	ray_cylinder_intersect_relay1(
	const t_ray *ray,
	const t_cylinder *cy,
	t_vector3f *ray_magnitude,
	t_intersection *inter
)
{
	t_vector3f		x;
	t_vector3f		magnitude;
	t_vector3f		hit_disk_center;

	x = v3fsub(&ray->origin, &cy->centre);
	magnitude.x = v3fdot(&ray->direction, &cy->normal)
		* ray_magnitude->x + v3fdot(&x, &cy->normal);
	magnitude.y = v3fdot(&ray->direction, &cy->normal)
		* ray_magnitude->y + v3fdot(&x, &cy->normal);
	if (ray_cylinder_intersect_relay2(ray, cy, &magnitude, inter) == 1)
	{
		ray_magnitude->z = magnitude.z;
		return (1);
	}
	if (magnitude.x < 0 || magnitude.x > cy->height)
		return (0);
	inter->hit_point = (t_vector3f){
			.x = ray->origin.x + ray->direction.x * ray_magnitude->x,
			.y = ray->origin.y + ray->direction.y * ray_magnitude->x,
			.z = ray->origin.z + ray->direction.z * ray_magnitude->x,
	};
	hit_disk_center = mul_v3fs1f(&cy->normal, magnitude.x);
	inter->normal = v3fsub(&(inter->hit_point), &cy->centre);
	inter->normal = v3fsub(&(inter->normal), &hit_disk_center);
	inter->normal = v3fnormalize(&(inter->normal));
	ray_magnitude->z = ray_magnitude->x;
	return (1);
}

int			ray_cylinder_intersect(
	const t_ray *ray,
	const t_cylinder *cy,
	float *t,
	t_intersection *inter
)
{
	t_vector3f	x;
	t_vector3f	abc;
	t_vector3f	magnitude;

	x = (t_vector3f){
		.x = ray->origin.x - cy->centre.x,
		.y = ray->origin.y - cy->centre.y,
		.z = ray->origin.z - cy->centre.z,
	};
	abc.x = v3fdot(&ray->direction, &ray->direction)
		- powf(v3fdot(&ray->direction, &cy->normal), 2.0);
	abc.y = 2 * (v3fdot(&ray->direction, &x)
		- v3fdot(&ray->direction, &cy->normal) * v3fdot(&x, &cy->normal));
	abc.z = v3fdot(&x, &x) - powf(v3fdot(&x, &cy->normal), 2)
		- (cy->diameter * cy->diameter);

	if (!quadratic(abc, &(magnitude.x), &(magnitude.y)))
		return 0;
	if (magnitude.x > FLT_MAX || magnitude.y <= 0)
		return 0;
	if (ray_cylinder_intersect_relay1(ray, cy, &magnitude, inter) == 0)
		return (0);
	*t = magnitude.z;
	return (1);
}
