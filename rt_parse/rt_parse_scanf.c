/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scanf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:11:35 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/12 15:23:47 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

void	free_fscanf_cylinder_inner(
	t_read_cylinder *rcy,
	char **centre_tmp,
	char **normal_tmp)
{
	rcy->centre.x = ft_atof(centre_tmp[0]);
	rcy->centre.y = ft_atof(centre_tmp[1]);
	rcy->centre.z = ft_atof(centre_tmp[2]);
	rcy->normal.x = ft_atof(normal_tmp[0]);
	rcy->normal.y = ft_atof(normal_tmp[1]);
	rcy->normal.z = ft_atof(normal_tmp[2]);
}

int	fscanf_cylinder(t_read_cylinder *rcy, char **tmp)
{
	char	**centre_tmp;
	char	**normal_tmp;
	char	**height_tmp;
	char	**radius_tmp;
	char	**color_tmp;

	if (!init_fscanf_cylinder(tmp, &centre_tmp, &normal_tmp, &height_tmp))
		return (0);
	if (!init_fscanf_cylinder2(tmp, &radius_tmp, &color_tmp))
	{
		free_4arr(tmp, centre_tmp, normal_tmp, height_tmp);
		return (0);
	}
	free_fscanf_cylinder_inner(rcy, centre_tmp, normal_tmp);
	rcy->height = ft_atof(tmp[3]);
	rcy->radius = ft_atof(tmp[4]);
	rcy->r = ft_atoi(color_tmp[0]);
	rcy->g = ft_atoi(color_tmp[1]);
	rcy->b = ft_atoi(color_tmp[2]);
	free_3arr(centre_tmp, normal_tmp, height_tmp);
	free_2arr(radius_tmp, color_tmp);
	return (1);
}

int	fscanf_sphere(t_read_sphere *rsp, char **tmp)
{
	char	**centre_tmp;
	char	**radius_tmp;
	char	**color_tmp;

	centre_tmp = rt_split(tmp[1], ',', 3);
	if (!centre_tmp)
		return (0);
	rsp->centre.x = ft_atof(centre_tmp[0]);
	rsp->centre.y = ft_atof(centre_tmp[1]);
	rsp->centre.z = ft_atof(centre_tmp[2]);
	radius_tmp = rt_split(tmp[2], ',', 1);
	if (!radius_tmp)
		return (0);
	rsp->radius = ft_atof(radius_tmp[0]);
	color_tmp = rt_split(tmp[3], ',', 3);
	if (!color_tmp)
		return (0);
	rsp->r = ft_atoi(color_tmp[0]);
	rsp->g = ft_atoi(color_tmp[1]);
	rsp->b = ft_atoi(color_tmp[2]);
	ft_free_arr(centre_tmp);
	ft_free_arr(radius_tmp);
	ft_free_arr(color_tmp);
	return (1);
}

int	fscanf_plane(t_read_plane *rpl, char **tmp)
{
	char	**centre_tmp;
	char	**normal_tmp;
	char	**color_tmp;

	if (!init_fscanf_plane(tmp, &centre_tmp, &normal_tmp, &color_tmp))
		return (0);
	rpl->centre.x = ft_atof(centre_tmp[0]);
	rpl->centre.y = ft_atof(centre_tmp[1]);
	rpl->centre.z = ft_atof(centre_tmp[2]);
	rpl->normal.x = ft_atof(normal_tmp[0]);
	rpl->normal.y = ft_atof(normal_tmp[1]);
	rpl->normal.z = ft_atof(normal_tmp[2]);
	rpl->r = ft_atoi(color_tmp[0]);
	rpl->g = ft_atoi(color_tmp[1]);
	rpl->b = ft_atoi(color_tmp[2]);
	ft_free_arr(centre_tmp);
	ft_free_arr(normal_tmp);
	ft_free_arr(color_tmp);
	return (1);
}

int	fscanf_camera(t_read_camera *camera, t_camera *ret, char **tmp)
{
	char	**position_tmp;
	char	**fov_tmp;
	char	**normal_tmp;

	(void)camera;
	if (!init_fscanf_camera(tmp, &position_tmp, &fov_tmp, &normal_tmp))
		return (0);
	(*ret).position.x = ft_atof(position_tmp[0]);
	(*ret).position.y = ft_atof(position_tmp[1]);
	(*ret).position.z = ft_atof(position_tmp[2]);
	(*ret).normal.x = ft_atof(normal_tmp[0]);
	(*ret).normal.y = ft_atof(normal_tmp[1]);
	(*ret).normal.z = ft_atof(normal_tmp[2]);
	(*ret).fov = ft_atoi(fov_tmp[0]);
	ft_free_arr(position_tmp);
	ft_free_arr(fov_tmp);
	ft_free_arr(normal_tmp);
	return (1);
}
