#include "rt.h"

#define FAIL 0

int	main(int argc, char *argv[])
{
	t_scene			*scenes;
	t_rt_renderer	renderer;
	t_sampler		sampler;
	t_printer		printer;

	if (check_files_name(argc, argv) == FAIL)
		rt_exit_with_msg("Invalid file name");
	if (rt_parse_files(scenes, argv, argc) == FAIL)
		rt_exit_with_msg("Syntax error");
	if (rt_mlx_init_printer(&printer, 700, 700))
		rt_exit_with_msg("Fail to init minilibX");
	sampler = create_default_sampler();
	if (rt_init_renderer(&renderer, &printer, &sampler) == FAIL)
		rt_exit_with_msg("Fail to init renderer");
	rt_render_scenes(&renderer, scenes);
}