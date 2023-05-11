/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:39:01 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/11 15:54:56 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_geo.h"

t_matrix4f	perspective(float fov, float n, float f)
{
	t_matrix4f	ret;
	const float	tmp = 1 / tanf((fov * PI / 180) / 2);

	ret = (t_matrix4f){
		.v = {
	{tmp, 0, 0, 0,},
	{0, tmp, 0, 0,},
	{0, 0, f / (f - n), -f * n / (f - n),},
	{0, 0, 1, 0},
	}
	};
	return (ret);
}

t_matrix4f	perspective_inverse(float fov, float n, float f)
{
	t_matrix4f	ret;
	const float	tmp = 1 / tanf((fov * PI / 180) / 2);

	ret = (t_matrix4f){
		.v = {
	{1 / tmp, 0, 0, 0,},
	{0, 1 / tmp, 0, 0,},
	{0, 0, 0, 1,},
	{0, 0, (f - n) / (f * n), -1 / n},
	}
	};
	return (ret);
}

t_matrix4f	lookat(
	t_vector3f *normal,
	const t_vector3f *up
)
{
	t_matrix4f	ret;
	t_vector3f	right;
	t_vector3f	new_up;

	right = v3fcross(up, normal);
	right = v3fnormalize(&right);
	new_up = v3fcross(normal, &right);
	ret = (t_matrix4f){
		.v = {
	{right.x, new_up.x, normal->x, 0},
	{right.y, new_up.y, normal->y, 0},
	{right.z, new_up.z, normal->z, 0},
	{0, 0, 0, 1}
	}
	};
	return (ret);
}
