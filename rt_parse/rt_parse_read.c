/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:13:25 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/15 04:39:09 by seonghyk         ###   ########.fr       */
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
	char			**bright_tmp;
	char			**color_tmp;

	if (!init_read_ambiant(line, &tmp, &bright_tmp, &color_tmp))
		return (0);
	ret.bright = ft_atof(bright_tmp[0]);
	ret.input_color = create_color(
			ft_atoi(color_tmp[0]),
			ft_atoi(color_tmp[1]),
			ft_atoi(color_tmp[2]));
	if (!is_valid_colour(&(ret.input_color))
		|| (ret.bright < 0 || ret.bright > 1))
	{
		free_3arr(tmp, color_tmp, bright_tmp);
		return (0);
	}
	ret.color = mul_color_s1f(&(ret.input_color), ret.bright);
	free_3arr(tmp, color_tmp, bright_tmp);
	scene->ambiant = ret;
	scene->ambiant_num += 1;
	return (1);
}

void	read_light_inner(t_scene *scene, char **ret_tmp, char **bright_tmp)
{
	scene->light.position.x = ft_atof(ret_tmp[0]);
	scene->light.position.y = ft_atof(ret_tmp[1]);
	scene->light.position.z = ft_atof(ret_tmp[2]);
	scene->light.bright = ft_atof(bright_tmp[0]);
}

int	read_light(t_scene *scene, char *line)
{
	char	**tmp;
	char	**ret_tmp;
	char	**bright_tmp;
	char	**color_tmp;
	t_color	color;

	if (!init_read_light(line, &tmp, &ret_tmp, &bright_tmp))
		return (0);
	if (!init_read_light2(tmp, &ret_tmp, &bright_tmp, &color_tmp))
		return (0);
	read_light_inner(scene, ret_tmp, bright_tmp);
	color = create_color(ft_atoi(color_tmp[0]),
			ft_atoi(color_tmp[1]),
			ft_atoi(color_tmp[2]));
	if (!is_valid_colour(&color)
		|| (scene->light.bright < 0 || scene->light.bright > 1))
	{
		free_4arr(tmp, ret_tmp, bright_tmp, color_tmp);
		return (0);
	}
	free_4arr(tmp, ret_tmp, bright_tmp, color_tmp);
	scene->light_num += 1;
	return (1);
}

int	read_camera(t_scene *scene, char *line)
{
	t_camera				ret;
	char					**tmp;
	t_read_camera			camera;

	tmp = rt_split(line, ' ', 4);
	while (tmp != NULL)
	{
		if (!fscanf_camera(&camera, &ret, tmp))
			break ;
		if (!is_valid_normal(&(ret.normal)) || (ret.fov < 0 || ret.fov > 180))
			break ;
		ret.normal = v3fnormalize(&(ret.normal));
		if (fabs(ret.normal.y) == 1)
			ret.camera2world = lookat(&(ret.normal), &(t_vector3f){0, 0, -1});
		else
			ret.camera2world = lookat(&(ret.normal), &(t_vector3f){0, 1, 0});
		ret.screen2camera = perspective_inverse(ret.fov, 0, FLT_MAX);
		ft_free_arr(tmp);
		scene->camera = ret;
		scene->camera_num += 1;
		return (1);
	}
	if (tmp != NULL)
		ft_free_arr(tmp);
	return (0);
}
