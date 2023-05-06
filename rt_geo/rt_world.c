/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:39:49 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/05 17:16:19 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_cylinder.h"
#include "rt_geo.h"
#include "rt_plane.h"
#include "rt_sphere.h"

int	ray_world_intersect_b(
	const t_ray *ray,
	const t_world *world,
	t_shape *except
)
{
	float			t;
	size_t			i;
	t_intersection	inter;

	i = -1;
	while (++i < world->elements_num)
	{
		if (ray_shape_intersect(ray, &world->shapes[i], &t, &inter))
		{
			if (&world->shapes[i] != except)
				return (1);
		}
	}
	return (0);
}

t_shape	*ray_world_intersect(
	const t_ray *ray,
	const t_world *world,
	t_intersection *inter_out
)
{
	t_entity		shape_entity;
	size_t			i;
	float			t;
	float			closest;
	t_intersection	inter_tmp;

	i = -1;
	shape_entity = i;
	closest = INFINITY;
	while (++i < world->elements_num)
	{
		if (ray_shape_intersect(ray, &world->shapes[i], &t, &inter_tmp))
		{
			if (t > 0 && t < closest)
			{
				*inter_out = inter_tmp;
				closest = t;
				shape_entity = i;
			}
		}
	}
	if (shape_entity == -1)
		return (NULL);
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
		return (ray_sphere_intersect(ray, shape->v, t, inter));
	else if (shape->type == CYLINDER)
		return (ray_cylinder_intersect(ray, shape->v, t, inter));
	else if (shape->type == PLANE)
		return (ray_plane_intersect(ray, shape->v, t, inter));
	else
		return (0);
}

int	rt_world_reserve(t_world *self, int n)
{
	t_shape	*tmp;
	size_t	i;

	tmp = malloc(sizeof(t_shape) * n);
	i = -1;
	while (++i < self->elements_num)
	{
		tmp[i] = self->shapes[i];
	}
	free(self->shapes);
	self->shapes = tmp;
	self->elements_size = n;
	return (1);
}

int	rt_world_append_shape(t_world *world, t_shape s)
{
	if (world->elements_num >= world->elements_size)
	{
		if (rt_world_reserve(world, world->elements_size * 2) == 0)
			return (0);
	}
	world->shapes[world->elements_num] = s;
	++world->elements_num;
	return (1);
}

t_world	*create_world(void)
{
	t_world	*ret;

	ret = malloc(sizeof(t_world));
	ret->elements_num = 0;
	ret->elements_size = 10;
	ret->shapes = malloc(sizeof(t_shape) * 10);
	return (ret);
}
