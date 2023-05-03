/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bounds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:44:51 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/02 21:44:52 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_BOUNDS_H
# define RT_BOUNDS_H

# include "../rt_math.h"
# include "rt_ray.h"

typedef struct s_bounds {
	t_vector3f	point_max;
	t_vector3f	point_min;
}	t_bounds;

typedef struct s_intersection {
	t_vector3f	hit_point;
	t_vector3f	normal;
}	t_intersection;

int	rt_bounds_ray_intersect(t_bounds *b, t_ray *r);

#endif