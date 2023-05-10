/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:41 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 17:34:05 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_geo.h"

t_color	mul_color_s1f(t_color *c, float s)
{
	t_color	ret;

	ret.v[COLOR_IDX_RED] = c->v[COLOR_IDX_RED] * s;
	ret.v[COLOR_IDX_BULE] = c->v[COLOR_IDX_BULE] * s;
	ret.v[COLOR_IDX_GREEN] = c->v[COLOR_IDX_GREEN] * s;
	ret.v[COLOR_IDX_ALPHA] = c->v[COLOR_IDX_ALPHA] * s;
	return (ret);
}

t_color	color_clip(t_color *c)
{
	t_color	ret;
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (c->v[i] < 0)
			ret.v[i] = 0;
		else if (c->v[i] > 1)
			ret.v[i] = 1;
		else
			ret.v[i] = c->v[i];
	}
	return (ret);
}

t_color	color_add(t_color *a, t_color *b)
{
	t_color	ret;

	ret.v[COLOR_IDX_RED] = a->v[COLOR_IDX_RED] + b->v[COLOR_IDX_RED];
	ret.v[COLOR_IDX_BULE] = a->v[COLOR_IDX_BULE] + b->v[COLOR_IDX_BULE];
	ret.v[COLOR_IDX_GREEN] = a->v[COLOR_IDX_GREEN] + b->v[COLOR_IDX_GREEN];
	ret.v[COLOR_IDX_ALPHA] = a->v[COLOR_IDX_ALPHA] + b->v[COLOR_IDX_ALPHA];
	return (ret);
}

t_color	create_color(int red, int green, int blue)
{
	t_color	ret;

	ret.v[COLOR_IDX_RED] = (float)red / 255.0;
	ret.v[COLOR_IDX_BULE] = (float)blue / 255.0;
	ret.v[COLOR_IDX_GREEN] = (float)green / 255.0;
	ret.v[COLOR_IDX_ALPHA] = 0;
	return (ret);
}
