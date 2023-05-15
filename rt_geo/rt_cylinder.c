/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:44:23 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/15 16:51:06 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include <math.h>
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

int	ray_cylinder_intersect_relay(
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

int	ray_cylinder_intersect_relay1(
	const t_ray *ray,
	const t_cylinder *cy,
	t_vector3f *m,
	t_intersection *inter
)
{
	t_vector3f	magnitude;
	t_plane		plane;

	m->z = m->x;
	if (m->x >= ray->min_t && m->x <= ray->max_t)
		if (ray_cylinder_intersect_relay(ray, cy, m->x, inter) == 1)
			return (1);
	m->z = m->y;
	if (m->y >= ray->min_t && m->y <= ray->max_t
		&& ray_cylinder_intersect_relay(ray, cy, m->y, inter) == 1)
	{
		if (m->x < ray->min_t && m->x > ray->max_t)
		{
			plane.normal = cy->normal;
			plane.centre = cy->centre;
			if (v3fdot(&cy->normal, &ray->direction) < 0)
			{
				t_vector3f	tmp = mul_v3fs1f(&cy->normal, cy->height);
				plane.centre = v3fadd(&(plane.centre), &tmp);
			}
			ray_plane_intersect(ray, &plane, &m->z, inter);
		}
		else 
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
	ret = ray_cylinder_intersect_relay1(ray, cy, &magnitude, inter);
	*t = magnitude.z;
	return (0);
}
