/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:45:47 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 02:13:53 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "rt_geo/rt_geo.h"
#include "rt_geo/rt_ray.h"
#include "rt_math.h"
#include "rt_renderer.h"

void	rt_scene_append_shape(t_scene *self, t_shape shape)
{
	if (self->world == NULL)
		rt_exit_with_msg("char *msg");
	rt_world_append_shape(self->world, shape);
}

int	rt_scene_init(t_scene *self)
{
	self->world = create_world();
	return (1);
}

void	release_scene(t_scene *scene)
{
	if (scene->world == NULL)
		return ;
	release_world(scene->world);
}
