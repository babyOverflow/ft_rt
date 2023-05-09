/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:10 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/09 15:32:10 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_math.h"

t_vector3f	v3fnag(const t_vector3f *v)
{
	return ((t_vector3f){
		.x = -v->x,
		.y = -v->y,
		.z = -v->z,
	});
}

double	v3fdot(const t_vector3f *v, const t_vector3f *u)
{
	double	ret;

	ret = v->x * u->x
		+ v->y * u->y
		+ v->z * u->z;
	return (ret);
}

float	v3fsize(const t_vector3f *v)
{
	float	tmp;

	tmp = v3fdot(v, v);
	return (sqrt(tmp));
}

t_vector3f	v3fadd(const t_vector3f *v, const t_vector3f *u)
{
	t_vector3f	ret;

	ret.x = v->x + u->x;
	ret.y = v->y + u->y;
	ret.z = v->z + u->z;
	return (ret);
}

t_vector3f	v3fsub(const t_vector3f *v, const t_vector3f *u)
{
	t_vector3f	ret;

	ret.x = v->x - u->x;
	ret.y = v->y - u->y;
	ret.z = v->z - u->z;
	return (ret);
}
