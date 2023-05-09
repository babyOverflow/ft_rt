/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sampler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:13:59 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 02:14:04 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "rt_renderer.h"

t_sampler	create_default_sampler(int resolution_x, int resolution_y)
{
	t_sampler	ret;

	ret.resolution_x = resolution_x;
	ret.resolution_y = resolution_y;
	ret.buf = malloc(sizeof(t_color) * resolution_x * resolution_y);
	return (ret);
}

void	release_sampler(t_sampler *sampler)
{
	if (sampler->buf != NULL)
		free(sampler->buf);
	sampler->buf = NULL;
}

void	rt_sampler_set_color(t_sampler *self, int x, int y, t_color color)
{
	self->buf[y * self->resolution_x + x] = color;
}

t_color	rt_sampler_get_color(const t_sampler *self, int x, int y)
{
	return (self->buf[y * self->resolution_x + x]);
}
