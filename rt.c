#include <stdio.h>
#include "rt.h"

#define FAIL 0



t_sampler	create_default_sampler(int resolution_x, int resolution_y)
{
	t_sampler	ret;
	ret.resolution_x = resolution_x;
	ret.resolution_y = resolution_y;
	ret.buf = malloc(sizeof(t_rgb) * resolution_x * resolution_y);
	return ret;
}

int	rt_init_renderer(
	t_rt_renderer *renderer,
	t_printer *printer,
	t_sampler *sampler
)
{
	renderer->printer = printer;
	renderer->sampler = sampler;
	return 1;
}

void	rt_exit_with_msg(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_scene			scenes;
	t_rt_renderer	renderer;
	t_sampler		sampler;
	t_printer		printer;

	if (check_files_name(argc, argv) == FAIL)
		rt_exit_with_msg("Invalid file name");
	rt_scene_init(&scenes);
	if (rt_parse_file(&scenes, argv[1]) == FAIL)
		rt_exit_with_msg("Syntax error");
	if (rt_mlx_init_printer(&printer, 1700, 700) == FAIL)
		rt_exit_with_msg("Fail to init minilibX");
	sampler = create_default_sampler(1700, 700);
	if (rt_init_renderer(&renderer, &printer, &sampler) == FAIL)
		rt_exit_with_msg("Fail to init renderer");
	rt_render_scenes(&renderer, &scenes);
}