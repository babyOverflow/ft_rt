/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:39:49 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/15 05:25:38 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_cylinder.h"
#include "rt_geo.h"
#include "rt_plane.h"
#include "rt_sphere.h"

int	rt_world_reserve(t_world *self, int n)
{
	t_shape	*tmp;
	size_t	i;

	tmp = malloc(sizeof(t_shape) * n);
	i = -1;
	while (++i < self->elements_num)
	{
		tmp[i] = self->shapes[i];
	}
	free(self->shapes);
	self->shapes = tmp;
	self->elements_size = n;
	return (1);
}

int	rt_world_append_shape(t_world *world, t_shape s)
{
	if (world->elements_num >= world->elements_size)
	{
		if (rt_world_reserve(world, world->elements_size * 2) == 0)
			return (0);
	}
	world->shapes[world->elements_num] = s;
	++world->elements_num;
	return (1);
}

t_world	*create_world(void)
{
	t_world	*ret;

	ret = malloc(sizeof(t_world));
	ret->elements_num = 0;
	ret->elements_size = 10;
	ret->shapes = malloc(sizeof(t_shape) * 10);
	return (ret);
}

void	release_world(t_world *world)
{
	size_t	i;

	if (world->shapes == NULL)
		return ;
	i = -1;
	while (++i < world->elements_num)
	{
		free(world->shapes[i].v);
	}
	free(world->shapes);
	world->shapes = NULL;
}
