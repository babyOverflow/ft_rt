/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read_shape.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:23:04 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/14 23:28:41 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "../rt_geo/rt_geo.h"
#include "../rt_math.h"
#include <string.h>
#include <float.h>
#include <fcntl.h>

int	read_shape(t_scene *scene, char *line)
{
	if (ft_strncmp(line, "sp", 2) == 0)
		return (read_sphere(scene, line));
	else if (ft_strncmp(line, "cy", 2) == 0)
		return (read_cylinder(scene, line));
	else if (ft_strncmp(line, "pl", 2) == 0)
		return (read_plane(scene, line));
	else
		return (0);
}

int	read_plane(t_scene *scene, char *line)
{
	t_shape			shape;
	char			**tmp;
	t_read_plane	rpl;
	t_plane			*pl;

	tmp = rt_split(line, ' ', 4);
	if (!tmp)
		return (0);
	if (!fscanf_plane(&rpl, tmp))
	{
		ft_free_arr(tmp);
		return (0);
	}
	shape.type = PLANE;
	shape.color = create_color(rpl.r, rpl.g, rpl.b);
	if (!is_valid_colour(&(shape.color)) || !is_valid_normal(&(rpl.normal)))
	{
		ft_free_arr(tmp);
		return (0);
	}
	pl = new_plane(rpl.centre, rpl.normal);
	shape.v = pl;
	ft_free_arr(tmp);
	rt_scene_append_shape(scene, shape);
	return (1);
}

int	read_cylinder(t_scene *scene, char *line)
{
	t_shape			ret;
	t_read_cylinder	rcy;
	char			**tmp;

	tmp = rt_split(line, ' ', 6);
	if (!tmp)
		return (0);
	if (!fscanf_cylinder(&rcy, tmp))
	{
		ft_free_arr(tmp);
		return (0);
	}
	ret.type = CYLINDER;
	ret.color = create_color(rcy.r, rcy.g, rcy.b);
	if (!is_valid_colour(&(ret.color)) || !is_valid_normal(&(rcy.normal))
		|| rcy.height < 0 || rcy.radius < 0)
	{
		ft_free_arr(tmp);
		return (0);
	}
	ret.v = new_cylinder(rcy.centre, rcy.normal, rcy.radius, rcy.height);
	ft_free_arr(tmp);
	rt_scene_append_shape(scene, ret);
	return (1);
}

int	read_sphere(t_scene *scene, char *line)
{
	t_shape			ret;
	char			**tmp;
	t_sphere		*sphere;
	t_read_sphere	rsp;

	tmp = rt_split(line, ' ', 4);
	if (!tmp)
		return (0);
	if (!fscanf_sphere(&rsp, tmp))
	{
		ft_free_arr(tmp);
		return (0);
	}
	ret.type = SPHERE;
	ret.color = create_color(rsp.r, rsp.g, rsp.b);
	if (!is_valid_colour(&(ret.color)) || rsp.radius < 0)
	{
		ft_free_arr(tmp);
		return (0);
	}
	sphere = new_sphere(rsp.centre, rsp.radius);
	ret.v = sphere;
	ft_free_arr(tmp);
	rt_scene_append_shape(scene, ret);
	return (1);
}
