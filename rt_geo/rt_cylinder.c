/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:44:23 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/16 02:01:11 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_cylinder.h"

t_cylinder	*new_cylinder(
	t_vector3f centre,
	t_vector3f normal,
	float height,
	float diameter
)
{
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	ret->centre = centre;
	ret->normal = v3fnormalize(&normal);
	ret->height = height;
	ret->diameter = diameter;
	return (ret);
}

