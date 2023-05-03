/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:13:25 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 17:36:36 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_geo/rt_geo.h"
#include "rt_math.h"
#include <string.h>
#include <float.h>
#include <fcntl.h>

t_shape	read_cylinder(char *line)
{
	t_shape			ret;
	t_read_cylinder	rcy;
	t_cylinder		*cy;
	char			**tmp;

	tmp = ft_split(line, ' ');
	fscanf_cylinder(&rcy, tmp);
	ret.type = CYLINDER;
	ret.color.v[3] = 0;
	ret.color.v[2] = rcy.r;
	ret.color.v[1] = rcy.g;
	ret.color.v[0] = rcy.b;
	cy = new_cylinder(rcy.centre, rcy.normal, rcy.radius, rcy.height);
	ret.v = cy;
	ft_free_arr(tmp);
	return (ret);
}

t_shape	read_sphere(char *line)
{
	t_shape			ret;
	char			**tmp;
	t_sphere		*sphere;
	t_read_sphere	rsp;

	tmp = ft_split(line, ' ');
	fscanf_sphere(&rsp, tmp);
	ret.type = SPHERE;
	ret.color.v[3] = 0;
	ret.color.v[2] = rsp.r;
	ret.color.v[1] = rsp.g;
	ret.color.v[0] = rsp.b;
	sphere = new_sphere(rsp.centre, rsp.radius);
	ret.v = sphere;
	ret.bounds = rt_sphere_get_bounds(sphere);
	ft_free_arr(tmp);
	return (ret);
}

t_ambiant	read_ambiant(char *line)
{
	t_ambiant		ret;
	char			**tmp;
	char			**color_tmp;

	tmp = ft_split(line, ' ');
	ret.bright = ft_atof(tmp[1]);
	color_tmp = ft_split(tmp[2], ',');
	ret.color.v[2] = ft_atoi(color_tmp[0]);
	ret.color.v[1] = ft_atoi(color_tmp[1]);
	ret.color.v[0] = ft_atoi(color_tmp[2]);
	ft_free_arr(color_tmp);
	ft_free_arr(tmp);
	return (ret);
}

t_light	read_light(char *line)
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
	return (ret);
}

t_camera	read_camera(char *line)
{
	t_camera		ret;
	char			**tmp;
	t_read_camera	camera;

	tmp = ft_split(line, ' ');
	fscanf_camera(&camera, &ret, tmp);
	ret.camera2world = lookat(&(ret.normal), &(t_vector3f){0, 1, 0});
	ret.screen2camera = perspective_inverse(ret.fov, 0, FLT_MAX);
	free(tmp);
	return (ret);
}

t_shape	read_plane(char *line)
{
	t_shape			ret;
	char			**tmp;
	t_read_plane	rpl;
	t_plane			*pl;

	tmp = ft_split(line, ' ');
	fscanf_plane(&rpl, tmp);
	ret.type = PLANE;
	ret.color.v[3] = 0;
	ret.color.v[2] = rpl.r;
	ret.color.v[1] = rpl.g;
	ret.color.v[0] = rpl.b;
	pl = new_plane(rpl.centre, rpl.normal);
	ret.v = pl;
	ft_free_arr(tmp);
	return (ret);
}

