#include "rt_geo.h"

t_shape	*ray_world_intersect(const t_ray *ray, const t_world *world)
{
	t_entity		shape_entity;
	int		i;
	float	t;
	float	closest;

	i = -1;
	shape_entity = i;
	closest = INFINITY;

	while (++i < world->elements_num)
	{
		if (ray_shape_intersect(ray, &world->shapes[i], &t))
		{
			if (t > 0 && t < closest)
			{
				closest = t;
				shape_entity = i;
			}
		}
	}
	if (shape_entity == -1)
		return NULL;
	return (&world->shapes[shape_entity]);
}

int	ray_shape_intersect(const t_ray *ray, const t_shape *shape, float *t)
{
	if (shape->type == SPHERE)
		return ray_sphepe_intersect(ray, shape->v, t);
	return 0;
}
