#ifndef RT_H
# define RT_H

#include "rt_geo.h"
#include "rt_renderer.h"


enum e_printer {
	RT_MLX
};

typedef struct s_printer {
	int		resolution_x;
	int		resolution_y;
	void	*data;
	void	(*print_image)(t_sampler *sampler);
}	t_printer;




int			rt_mlx_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y);
t_sampler	create_default_sampler();
int			rt_init_renderer(
				t_rt_renderer *renderer,
				t_printer *printer,
				t_sampler *sampler);
int			rt_render_scenes(
				t_rt_renderer *renderer,
				t_scene *scenes);

void		rt_exit_with_msg(char *msg);

#endif
