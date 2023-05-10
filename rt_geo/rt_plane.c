/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:50:12 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 18:40:20 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "rt_plane.h"

t_plane	*new_plane(t_vector3f centre, t_vector3f normal)
{
	t_plane	*ret;

	ret = malloc(sizeof(t_plane));
	ret->centre = centre;
	ret->normal = v3fnormalize(&normal);
	return (ret);
}

int	ray_plane_intersect(
	const t_ray *ray,
	const t_plane *plane,
	float *t_out,
	t_intersection *inter)
{
	t_vector3f	ray2centre;
	t_vector3f	hit_point;
	float		t;
	float		denom;

	ray2centre = v3fsub(&ray->origin, &plane->centre);
	t = -v3fdot(&ray2centre, &plane->normal);
	denom = v3fdot(&ray->direction, &plane->normal);
	t /= denom;
	if (t > ray->max_t || t <= ray->min_t)
		return (0);
	hit_point = mul_v3fs1f(&ray->direction, t);
	inter->hit_point = v3fadd(&hit_point, &ray->origin);
	if (denom > 0)
		inter->normal = v3fnag(&plane->normal);
	else
		inter->normal = plane->normal;
	*t_out = t;
	return (1);
}
