/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:13:25 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/10 16:50:42 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "../rt_geo/rt_geo.h"
#include "../rt_math.h"
#include <string.h>
#include <float.h>
#include <fcntl.h>

int	read_ambiant(t_scene *scene, char *line)
{
	t_ambiant		ret;
	char			**tmp;
	char			**color_tmp;

	tmp = ft_split(line, ' ');
	ret.bright = ft_atof(tmp[1]);
	color_tmp = ft_split(tmp[2], ',');
	ret.input_color = create_color(
			ft_atoi(color_tmp[0]),
			ft_atoi(color_tmp[1]),
			ft_atoi(color_tmp[2]));
	ret.color = mul_color_s1f(&(ret.input_color), ret.bright);
	ft_free_arr(color_tmp);
	ft_free_arr(tmp);
	scene->ambiant = ret;
	return (1);
}

int	read_light(t_scene *scene, char *line)
{
	t_light			ret;
	char			**tmp;
	char			**ret_tmp;
	char			**color_tmp;
	t_read_light	light;

	tmp = ft_split(line, ' ');
	ret_tmp = ft_split(tmp[1], ',');
	ret.position.x = ft_atof(ret_tmp[0]);
	ret.position.y = ft_atof(ret_tmp[1]);
	ret.position.z = ft_atof(ret_tmp[2]);
	ret.bright = ft_atof(tmp[2]);
	color_tmp = ft_split(tmp[3], ',');
	light.r = ft_atoi(color_tmp[0]);
	light.g = ft_atoi(color_tmp[1]);
	light.b = ft_atoi(color_tmp[2]);
	ft_free_arr(color_tmp);
	ft_free_arr(ret_tmp);
	ft_free_arr(tmp);
	scene->light = ret;
	return (1);
}

int	read_camera(t_scene *scene, char *line)
{
	t_camera		ret;
	char			**tmp;
	t_read_camera	camera;

	tmp = ft_split(line, ' ');
	fscanf_camera(&camera, &ret, tmp);
	ret.camera2world = lookat(&(ret.normal), &(t_vector3f){0, 1, 0});
	ret.screen2camera = perspective_inverse(ret.fov, 0, FLT_MAX);
	free(tmp);
	scene->camera = ret;
	return (1);
}
