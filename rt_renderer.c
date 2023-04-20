#include "rt.h"
#include "rt_geo/rt_geo.h"
#include "rt_math.h"
#include "rt_renderer.h"

t_ray	gen_ray(
			const t_sampler *sampler,
			const t_camera *camera,
			const t_vector2i *position
)
{
	t_vector3f			direct;
	t_vector3f	pre_direct = (t_vector3f){
		.x = 2 * ((float)position->x / (float)sampler->resolution_x - 0.5),
		.y = 2 * (-(float)position->y / (float)sampler->resolution_y + 0.5),
		.z = 1.f 
	};
	pre_direct = v3fnormalize(&pre_direct);
	direct = prouct_m4fv3f(&camera->camera2world, &pre_direct);
	return (t_ray){.origin = camera->position, .direction = direct};
}


t_rgb	trace_ray(t_ray *ray, t_scene *scene)
{
	const t_world	*world = scene->world;
	t_shape		*shape;
	t_intersection		intersection;
	float		t;

	shape = ray_world_intersect(ray, scene->world, &t, &intersection);
	if (shape == NULL)
		return (t_rgb){0, 0, 0, 0};
	t_vector3f	light_dir = {
		.x = intersection.hit_point.x - scene->light.position.x,
		.y = intersection.hit_point.y - scene->light.position.y,
		.z = intersection.hit_point.z - scene->light.position.z
	};
	light_dir = v3fnormalize(&light_dir);
	float d = -v3fdot(&(intersection.normal), &(light_dir));
	if (d < 0)
		d = 0;

	t_rgb	ret = {
		.v[0] = shape->color.v[0] * d ,
		.v[1] = shape->color.v[1] * d ,
		.v[2] = shape->color.v[2] * d ,
		.v[3] = shape->color.v[3] ,
	};
	return (ret);
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

int		rt_scene_init(t_scene *self)
{
	self->world = create_world();
	return 1;
}


void	rt_sampler_set_color(t_sampler *self, int x, int y, t_rgb color)
{
	self->buf[y * self->resolution_x + x] = color;
}

t_rgb	rt_sampler_get_color(const t_sampler *self, int x, int y)
{

	return self->buf[y * self->resolution_x + x];
}
