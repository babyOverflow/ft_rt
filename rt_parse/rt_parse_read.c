/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:13:25 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 15:40:02 by seonghyk         ###   ########.fr       */
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
	if (!is_valid_colour(&(ret.input_color)))
		return (0);
	if (ret.bright < 0 || ret.bright > 1)
		return (0);
	ret.color = mul_color_s1f(&(ret.input_color), ret.bright);
	ft_free_arr(color_tmp);
	ft_free_arr(tmp);
	scene->ambiant = ret;
	scene->ambiant_num += 1;
	return (1);
}

int	read_light(t_scene *scene, char *line)
{
	char	**tmp;
	char	**ret_tmp;
	char	**color_tmp;
	t_color	color;

	tmp = ft_split(line, ' ');
	ret_tmp = ft_split(tmp[1], ',');
	scene->light.position.x = ft_atof(ret_tmp[0]);
	scene->light.position.y = ft_atof(ret_tmp[1]);
	scene->light.position.z = ft_atof(ret_tmp[2]);
	scene->light.bright = ft_atof(tmp[2]);
	color_tmp = ft_split(tmp[3], ',');
	color = create_color(ft_atoi(color_tmp[0]),
			ft_atoi(color_tmp[1]),
			ft_atoi(color_tmp[2]));
	if (!is_valid_colour(&color))
		return (0);
	if (scene->light.bright < 0 || scene->light.bright > 1)
		return (0);
	ft_free_arr(color_tmp);
	ft_free_arr(ret_tmp);
	ft_free_arr(tmp);
	scene->light_num += 1;
	return (1);
}

int	read_camera(t_scene *scene, char *line)
{
	t_camera		ret;
	char			**tmp;
	t_read_camera	camera;

	tmp = ft_split(line, ' ');
	fscanf_camera(&camera, &ret, tmp);
	if (!is_valid_normal(&(ret.normal)))
		return (0);
	ret.normal = v3fnormalize(&(ret.normal));
	if (ret.normal.y == UP_DIRECTION.y)
		return (0);
	if (ret.fov < 0 || ret.fov > 180)
		return (0);
	ret.camera2world = lookat(&(ret.normal), &UP_DIRECTION);
	ret.screen2camera = perspective_inverse(ret.fov, 0, FLT_MAX);
	ft_free_arr(tmp);
	scene->camera = ret;
	scene->camera_num += 1;
	return (1);
}
