/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:41:23 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/02 16:41:24 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SPHERE_H
# define RT_SPHERE_H

# include "../rt_math.h"
# include "rt_bounds.h"

typedef struct s_sphere {
	t_vector3f	centre;
	float		radius;
}	t_sphere;

t_sphere	*new_sphere(t_vector3f centre, float radius);
t_bounds	rt_sphere_get_bounds(t_sphere *self);
int			ray_sphere_intersect(
				const t_ray *ray,
				const t_sphere *shape,
				float *t,
				t_intersection *inter);

#endif //RT_SPHERE_H
