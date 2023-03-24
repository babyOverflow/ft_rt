#ifndef RT_RENDERER_H
# define RT_RENDERER_H

# include "rt_geo/rt_geo.h"

typedef struct s_sampler {
	int		resolution_x;
	int		resolution_y;
	t_rgb	*buf;
}	t_sampler;

typedef struct s_camera {
	t_vector3f	position;
	t_vector3f	normal;
	int			fov;
}	t_camera;

typedef struct s_rt_renderer {
	t_sampler	*sampler;
}	t_rt_renderer;

typedef struct s_ambiant {
	t_rgb	color;
	float	bright;
}	t_ambiant;

typedef struct s_light {
	t_vector3f	position;
	float		bright;
}	t_light;

typedef struct s_scene {
	t_world		*world;
	t_camera	camera;
	t_ambiant	ambiant;	
	t_light		light;
}	t_scene;

void	gen_ray(int x, int y, t_ray *ray, t_camera *camera);
t_rgb	trace_ray(t_ray *ray, t_scene *scene);
void	rt_sampler_set_color(int x, int y, t_rgb color);

void	rt_scene_append_shape(t_scene *self, t_shape shape);

#endif //RT_RENDERER_H