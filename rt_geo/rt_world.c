#include "rt_geo.h"
#include "rt_sphere.h"

t_shape	*ray_world_intersect(
	const t_ray *ray,
	const t_world *world,
	float *t,
	t_intersection *inter
)
{
	t_entity		shape_entity;
	int		i;
	float	closest;
	t_intersection	closest_inter;

	i = -1;
	shape_entity = i;
	closest = INFINITY;
	while (++i < world->elements_num)
	{
		if (ray_shape_intersect(ray, &world->shapes[i], t, inter))
		{
			if (*t > 0 && *t < closest)
			{
				closest_inter = *inter;
				closest = *t;
				shape_entity = i;
			}
		}
	}
	*inter = closest_inter;
	*t = closest;
	if (shape_entity == -1)
		return NULL;
	return (&world->shapes[shape_entity]);
}

int	ray_shape_intersect(
	const t_ray *ray,
	const t_shape *shape,
	float *t,
	t_intersection *inter
)
{
	if (shape->type == SPHERE)
		return ray_sphere_intersect(ray, shape->v, t, inter);
	return 0;
}

int	rt_world_reserve(t_world *self, int n)
{
	t_shape	*tmp;
	int		i;

	tmp = malloc(sizeof(t_shape) * n);
	i = -1;
	while (++i < self->elements_num)
	{
		tmp[i] = self->shapes[i];
	}
	free(self->shapes);
	self->shapes = tmp;
	self->elements_size = n;
	return 1;
}

int		rt_world_append_shape(t_world* world, t_shape s)
{
	if (world->elements_num >= world->elements_size)
	{
		if (rt_world_reserve(world, world->elements_size * 2) == 0)
			return (0);
	}
	world->shapes[world->elements_num] = s;
	++world->elements_num;
	return 1;
}

t_world	*create_world()
{
	t_world	*ret;

	ret = malloc(sizeof(t_world));
	ret->elements_num = 0;
	ret->elements_size = 10;
	ret->shapes	= malloc(sizeof(t_shape) * 10);
	return (ret);
}
