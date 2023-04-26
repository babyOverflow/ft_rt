#include <stdlib.h>
#include <float.h>
#include "rt_cylinder.h"

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
	ret->normal = normal;
	ret->height = height;
	ret->diameter = diameter;
	return (ret);
}

// int			ray_cylinder_intersect(
// 	const t_ray *ray,
// 	const t_cylinder *cy,
// 	float *t,
// 	t_intersection *inter
// )
// {
// 	t_vector3f	right = v3fcross(&(ray->direction), &(cy->normal));
// }
