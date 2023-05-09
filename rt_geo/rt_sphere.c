/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:47:59 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/09 13:30:42 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "rt_sphere.h"

int	ray_sphere_intersect(
	const t_ray *ray,
	const t_sphere *sphere,
	float *t,
	t_intersection *inter)
{
	t_ray		r;
	t_vector3f	abc;
	float		t0;
	float		t1;

	r.direction = ray->direction;
	r.origin = v3fsub(&ray->origin, &sphere->centre);
	abc.x = v3fdot(&(r.direction), &(r.direction));
	abc.y = 2 * v3fdot(&(r.direction), &(r.origin));
	abc.z = v3fdot(&(r.origin), &(r.origin)) - sphere->radius * sphere->radius;
	if (!quadratic(abc, &t0, &t1))
		return (0);
	if (t0 > ray->max_t || t1 <= ray->min_t)
		return (0);
	*t = t0;
	if (*t < 0)
		*t = t1;
	inter->hit_point = mul_v3fs1f(&ray->direction, *t);
	inter->hit_point = v3fadd(&ray->origin, &inter->hit_point);
	inter->normal = v3fsub(&inter->hit_point, &sphere->centre);
	inter->normal = v3fnormalize(&inter->normal);
	return (1);
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
