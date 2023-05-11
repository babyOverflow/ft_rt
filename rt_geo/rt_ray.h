/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:31 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/11 16:50:44 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAY_H
# define RT_RAY_H

# include "../rt_math.h"

typedef struct s_ray {
	t_vector3f	direction;
	t_vector3f	origin;
	float		max_t;
	float		min_t;
}	t_ray;

typedef struct s_intersection {
	t_vector3f	hit_point;
	t_vector3f	normal;
}	t_intersection;

#endif //RT_RAY_H