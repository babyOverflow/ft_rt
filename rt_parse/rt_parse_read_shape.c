/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read_shape.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:23:04 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 16:50:58 by seonghyk         ###   ########.fr       */
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

	tmp = ft_split(line, ' ');
	fscanf_plane(&rpl, tmp);
	shape.type = PLANE;
	shape.color = create_color(rpl.r, rpl.g, rpl.b);
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
	t_cylinder		*cy;
	char			**tmp;

	tmp = ft_split(line, ' ');
	fscanf_cylinder(&rcy, tmp);
	ret.type = CYLINDER;
	ret.color = create_color(rcy.r, rcy.g, rcy.b);
	cy = new_cylinder(rcy.centre, rcy.normal, rcy.radius, rcy.height);
	ret.v = cy;
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

	tmp = ft_split(line, ' ');
	fscanf_sphere(&rsp, tmp);
	ret.type = SPHERE;
	ret.color = create_color(rsp.r, rsp.g, rsp.b);
	sphere = new_sphere(rsp.centre, rsp.radius);
	ret.v = sphere;
	ret.bounds = rt_sphere_get_bounds(sphere);
	ft_free_arr(tmp);
	rt_scene_append_shape(scene, ret);
	return (1);
}
