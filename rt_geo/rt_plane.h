/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:24 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/11 16:52:12 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PLANE_H
# define RT_PLANE_H

# include "../rt_math.h"
# include "rt_geo.h"

typedef struct s_plane {
	t_vector3f	centre;
	t_vector3f	normal;
}	t_plane;

t_plane		*new_plane(t_vector3f centre, t_vector3f normal);
int			ray_plane_intersect(
				const t_ray *ray,
				const t_plane *plane,
				float *t,
				t_intersection *inter);

#endif //RT_PLANE_H
