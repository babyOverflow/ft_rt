/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:50:12 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/02 17:09:11 by seonghyk         ###   ########.fr       */
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
	ret->normal = normal;
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

	ray2centre = v3fsub(&ray->origin, &plane->centre);
	t = -v3fdot(&ray2centre, &plane->normal);
	t /= v3fdot(&ray->direction, &plane->normal);
	if (t > FLT_MAX || t <= 0)
		return (0);
	hit_point = mul_v3fs1f(&ray->direction, t);
	inter->hit_point = v3fadd(&hit_point, &ray->origin);
	inter->normal = plane->normal;
	*t_out = t;
	return (1);
}
