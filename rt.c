/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:27:30 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 02:12:40 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "rt.h"
#include "rt_renderer.h"

#define FAIL 0

int	rt_init_renderer(
	t_rt_renderer *renderer,
	t_printer *printer,
	t_sampler *sampler
)
{
	renderer->printer = printer;
	renderer->sampler = sampler;
	return (1);
}

void	rt_exit_with_msg(char *str)
{
	size_t	len;

	ft_strlen(str);
	write(STDOUT_FILENO, str, len);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_scene			scenes;
	t_rt_renderer	renderer;
	t_sampler		sampler;
	t_printer		printer;

	if (check_files_name(argc, argv) == FAIL)
		rt_exit_with_msg("Error");
	rt_scene_init(&scenes);
	if (rt_parse_file(&scenes, argv[1]) == FAIL)
	{
		release_scene(&scenes);
		rt_exit_with_msg("Error");
	}
	sampler = create_default_sampler(700, 700);
	rt_mlx_init_printer(&printer, 700, 700);
	rt_init_renderer(&renderer, &printer, &sampler);
	rt_render_scenes(&renderer, &scenes);
	release_scene(&scenes);
	release_sampler(&sampler);
	release_printer(&printer);
}
