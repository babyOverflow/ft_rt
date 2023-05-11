/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scanf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:11:35 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 10:56:53 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

void	fscanf_cylinder(t_read_cylinder *rcy, char **tmp)
{
	char	**centre_tmp;
	char	**normal_tmp;
	char	**color_tmp;

	centre_tmp = ft_split(tmp[1], ',');
	rcy->centre.x = ft_atof(centre_tmp[0]);
	rcy->centre.y = ft_atof(centre_tmp[1]);
	rcy->centre.z = ft_atof(centre_tmp[2]);
	normal_tmp = ft_split(tmp[2], ',');
	rcy->normal.x = ft_atof(normal_tmp[0]);
	rcy->normal.y = ft_atof(normal_tmp[1]);
	rcy->normal.z = ft_atof(normal_tmp[2]);
	rcy->height = ft_atof(tmp[3]);
	rcy->radius = ft_atof(tmp[4]);
	color_tmp = ft_split(tmp[5], ',');
	rcy->r = ft_atoi(color_tmp[0]);
	rcy->g = ft_atoi(color_tmp[1]);
	rcy->b = ft_atoi(color_tmp[2]);
	ft_free_arr(centre_tmp);
	ft_free_arr(normal_tmp);
	ft_free_arr(color_tmp);
}

void	fscanf_sphere(t_read_sphere *rsp, char **tmp)
{
	char	**centre_tmp;
	char	**color_tmp;

	centre_tmp = ft_split(tmp[1], ',');
	rsp->centre.x = ft_atof(centre_tmp[0]);
	rsp->centre.y = ft_atof(centre_tmp[1]);
	rsp->centre.z = ft_atof(centre_tmp[2]);
	rsp->radius = ft_atof(tmp[2]);
	color_tmp = ft_split(tmp[3], ',');
	rsp->r = ft_atoi(color_tmp[0]);
	rsp->g = ft_atoi(color_tmp[1]);
	rsp->b = ft_atoi(color_tmp[2]);
	ft_free_arr(centre_tmp);
	ft_free_arr(color_tmp);
}

void	fscanf_plane(t_read_plane *rpl, char **tmp)
{
	char	**centre_tmp;
	char	**normal_tmp;
	char	**color_tmp;

	centre_tmp = ft_split(tmp[1], ',');
	rpl->centre.x = ft_atof(centre_tmp[0]);
	rpl->centre.y = ft_atof(centre_tmp[1]);
	rpl->centre.z = ft_atof(centre_tmp[2]);
	normal_tmp = ft_split(tmp[2], ',');
	rpl->normal.x = ft_atof(normal_tmp[0]);
	rpl->normal.y = ft_atof(normal_tmp[1]);
	rpl->normal.z = ft_atof(normal_tmp[2]);
	color_tmp = ft_split(tmp[3], ',');
	rpl->r = ft_atoi(color_tmp[0]);
	rpl->g = ft_atoi(color_tmp[1]);
	rpl->b = ft_atoi(color_tmp[2]);
	ft_free_arr(centre_tmp);
	ft_free_arr(normal_tmp);
	ft_free_arr(color_tmp);
}

void	fscanf_camera(t_read_camera *camera, t_camera *ret, char **tmp)
{
	char	**position_tmp;
	char	**normal_tmp;

	position_tmp = ft_split(tmp[1], ',');
	(*ret).position.x = ft_atof(position_tmp[0]);
	(*ret).position.y = ft_atof(position_tmp[1]);
	(*ret).position.z = ft_atof(position_tmp[2]);
	normal_tmp = ft_split(tmp[2], ',');
	(*ret).normal.x = ft_atof(normal_tmp[0]);
	(*ret).normal.y = ft_atof(normal_tmp[1]);
	(*ret).normal.z = ft_atof(normal_tmp[2]);
	(*ret).fov = ft_atoi(tmp[3]);
	ft_free_arr(position_tmp);
	ft_free_arr(normal_tmp);
}
