#include "rt.h"
#include "rt_geo/rt_geo.h"
#include "rt_renderer.h"

t_ray	gen_ray(
			const t_sampler *sampler,
			const t_camera *camera,
			const t_vector2i *position
)
{
	t_vector3f			direct;
	const t_vector3f	pre_direct = (t_vector3f){
		.x = (float)position->x / (float)sampler->resolution_x,
		.y = (float)position->y / (float)sampler->resolution_y,
		.z = 0
	};
	direct = prouct_m4fv3f(&camera->world2camera, &pre_direct);
	return (t_ray){.origin = camera->position, .direction = direct};
}


t_rgb	trace_ray(t_ray *ray, t_scene *scene)
{
	const t_world	*world = scene->world;
	t_shape	*shape;

	shape = ray_world_intrsect(ray, scene->world);
	return (shape->color);
}

int	rt_render_scenes(t_rt_renderer *renderer, t_scene *scenes)
{
	t_sampler	*sampler = renderer->sampler;
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

			gen_ray(renderer->sampler, &scenes->camera, &sample);
			color = trace_ray(&ray, scenes);
			rt_sampler_set_color(sampler, sample.x, sample.y, color);
		}
	}
	renderer->printer->print_image(renderer);
	return (1);
}