#include "rt.h"
#include "rt_renderer.h"

int	rt_render_scenes(t_rt_renderer *renderer, t_scene *scenes)
{
	const t_sampler	*sampler = renderer->sampler;
	t_ray			ray;
	int				x;
	int				y;

	y = -1;
	while (++y < sampler->resolution_y)
	{
		x = -1;
		while (++x < sampler->resolution_x)
		{
			gen_ray(x, y, &ray, scenes->camera);
		}
	}
}