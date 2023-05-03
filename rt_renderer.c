/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:33:01 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/03 11:33:02 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "rt_geo/rt_geo.h"
#include "rt_geo/rt_ray.h"
#include "rt_math.h"
#include "rt_renderer.h"

t_ray	gen_ray(
			const t_sampler *sampler,
			const t_camera *camera,
			const t_vector2i *position
)
{
	t_vector3f	direct;
	t_vector3f	pre_direct;
	float		resolution_max;

	resolution_max = sampler->resolution_x;
	if (sampler->resolution_y > sampler->resolution_x)
		resolution_max = sampler->resolution_y;
	pre_direct = (t_vector3f){
		.x = 2 * (
			((float)position->x - (sampler->resolution_x / 2.0))
			/ resolution_max),
		.y = 2 * (
			(-(float)position->y + (sampler->resolution_y / 2.0))
			/ resolution_max),
		.z = 1.0f
	};
	pre_direct = v3fnormalize(&pre_direct);
	direct = prouct_m4fv3f(&camera->screen2camera, &pre_direct);
	direct = prouct_m4fv3f(&camera->camera2world, &direct);
	return ((t_ray){.origin = camera->position, .direction = direct});
}

t_rgb	trace_ray(t_ray *ray, t_scene *scene)
{
	t_shape			*shape;
	t_intersection	intersection;
	float			t;
	float			d;
	t_ray			ray_hit2ligh;

	shape = ray_world_intersect(ray, scene->world, &t, &intersection);
	if (shape == NULL)
		return ((t_rgb){0, 0, 0, 0});
	ray_hit2ligh.origin = intersection.hit_point;
	ray_hit2ligh.direction = v3fsub(
			&(scene->light.position), &(intersection.hit_point));
	ray_hit2ligh.direction = v3fnormalize(&(ray_hit2ligh.direction));
	d = 0;
	if (ray_world_intersect_b(&ray_hit2ligh, scene->world, shape) == 0)
		d = v3fdot(&(intersection.normal), &(ray_hit2ligh.direction));
	if (d < 0)
		d = 0;
	d += scene->ambiant.bright;
	if (d > 1)
		d = 1;
	return ((t_rgb){
		.v[0] = shape->color.v[0] * d, .v[1] = shape->color.v[1] * d,
		.v[2] = shape->color.v[2] * d, .v[3] = shape->color.v[3],
	});
}

int	rt_render_scenes(t_rt_renderer *renderer, t_scene *scenes)
{
	t_sampler	*sampler;
	t_ray		ray;
	t_vector2i	sample;
	t_rgb		color;

	sampler = renderer->sampler;
	sample.y = -1;
	while (++sample.y < sampler->resolution_y)
	{
		sample.x = -1;
		while (++sample.x < sampler->resolution_x)
		{
			ray = gen_ray(renderer->sampler, &scenes->camera, &sample);
			color = trace_ray(&ray, scenes);
			rt_sampler_set_color(sampler, sample.x, sample.y, color);
		}
	}
	renderer->printer->print_image(renderer);
	return (1);
}

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

void	rt_sampler_set_color(t_sampler *self, int x, int y, t_rgb color)
{
	self->buf[y * self->resolution_x + x] = color;
}

t_rgb	rt_sampler_get_color(const t_sampler *self, int x, int y)
{
	return (self->buf[y * self->resolution_x + x]);
}
