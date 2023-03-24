#include "rt.h"
#include "rt_geo.h"
#include "rt_renderer.h"



t_rgb	trace_ray(t_ray *ray, t_scene *scene)
{
	const t_world	*world = scene->world;
	t_shape	*shape;

	shape = ray_world_intersect(ray, world);
	return (shape->color);
}

int	rt_render_scenes(t_rt_renderer *renderer, t_scene *scenes)
{
	const t_sampler	*sampler = renderer->sampler;
	t_ray			ray;
	int				x;
	int				y;
	t_rgb			color;

	y = -1;
	while (++y < sampler->resolution_y)
	{
		x = -1;
		while (++x < sampler->resolution_x)
		{
			gen_ray(x, y, &ray, scenes->camera);
			color = trace_ray(&ray, scenes);
			rt_sampler_set_color(x, y, color);
		}
	}
	return (1);
}