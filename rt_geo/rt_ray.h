/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:31 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/02 16:48:34 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAY_H
# define RT_RAY_H

# include "../rt_math.h"

typedef struct s_ray {
	t_vector3f	direction;
	t_vector3f	origin;
}	t_ray;

#endif //RT_RAY_H