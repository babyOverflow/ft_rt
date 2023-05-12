/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:36:32 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/12 18:27:28 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_cylinder.h"
#include "rt_geo.h"
#include "rt_plane.h"
#include "rt_sphere.h"

int	ray_world_intersect_b(
	const t_ray *ray,
	const t_world *world
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
