/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:24 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/02 16:49:26 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PLANE_H
# define RT_PLANE_H

# include "../rt_math.h"
# include "rt_bounds.h"

typedef struct s_plane {
	t_vector3f	centre;
	t_vector3f	normal;
}	t_plane;

t_plane		*new_plane(t_vector3f centre, t_vector3f normal);
t_bounds	rt_plane_get_bounds(t_plane *self);
int			ray_plane_intersect(
				const t_ray *ray,
				const t_plane *plane,
				float *t,
				t_intersection *inter);

#endif //RT_PLANE_H
