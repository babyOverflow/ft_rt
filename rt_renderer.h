/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_renderer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:38:29 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/11 12:07:00 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDERER_H
# define RT_RENDERER_H

# include "rt_geo/rt_geo.h"
# include "rt_math.h"

typedef struct s_printer {
	int		resolution_x;
	int		resolution_y;
	void	*data;
	void	(*print_image)(void *printer);
}	t_printer;

typedef struct s_sampler {
	int		resolution_x;
	int		resolution_y;
	t_color	*buf;
}	t_sampler;

typedef struct s_camera {
	t_vector3f	position;
	t_vector3f	normal;
	int			fov;
	t_matrix4f	camera2world;
	t_matrix4f	screen2camera;
}	t_camera;

typedef struct s_rt_renderer {
	t_sampler	*sampler;
	t_printer	*printer;
}	t_rt_renderer;

typedef struct s_ambiant {
	t_color	color;
	t_color	input_color;
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

t_color		trace_ray(t_ray *ray, t_scene *scene);
t_ray		gen_ray(
				const t_sampler *sample,
				const t_camera *camera,
				const t_vector2i *position
				);
t_sampler	create_default_sampler(int resolution_x, int resolution_y);
void		release_sampler(t_sampler *sampler);
void		rt_sampler_set_color(t_sampler *self, int x, int y, t_color color);
t_color		rt_sampler_get_color(const t_sampler *self, int x, int y);

void		rt_scene_append_shape(t_scene *self, t_shape shape);
void		release_scene(t_scene *scene);
int			rt_scene_init(t_scene *self);

int			rt_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y);
void		release_printer(t_printer *printer);

#endif //RT_RENDERER_H
