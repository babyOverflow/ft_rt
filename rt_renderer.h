#ifndef RT_RENDERER_H
# define RT_RENDERER_H

# include "rt_geo.h"

typedef struct s_sampler {
	int		resolution_x;
	int		resolution_y;

}	t_sampler;

typedef struct s_camera {

}	t_camera;

typedef struct s_rt_renderer {
	t_sampler	*sampler;
}	t_rt_renderer;


typedef struct s_scene {
	t_camera	*camera;
	t_world		*world;
}	t_scene;

void	gen_ray(int x, int y, t_ray *ray, t_camera *camera);
t_rgb	trace_ray(t_ray *ray, t_scene *scene);
void	rt_sampler_set_color(int x, int y, t_rgb color);

#endif //RT_RENDERER_H