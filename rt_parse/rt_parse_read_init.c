/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:47:01 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/12 15:19:59 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

int	init_read_ambiant(
		char *line,
		char ***tmp,
		char ***bright_tmp,
		char ***color_tmp
)
{
	*tmp = rt_split(line, ' ', 3);
	if (!*tmp)
		return (0);
	*bright_tmp = rt_split((*tmp)[1], ',', 1);
	if (!*bright_tmp)
	{
		ft_free_arr(*tmp);
		return (0);
	}
	*color_tmp = rt_split((*tmp)[2], ',', 3);
	if (!*color_tmp)
	{
		free_2arr(*tmp, *bright_tmp);
		return (0);
	}
	return (1);
}

int	init_read_light(
		char *line,
		char ***tmp,
		char ***ret_tmp,
		char ***bright_tmp
)
{
	*tmp = rt_split(line, ' ', 4);
	if (!*tmp)
		return (0);
	*ret_tmp = rt_split((*tmp)[1], ',', 3);
	if (!*ret_tmp)
	{
		ft_free_arr(*tmp);
		return (0);
	}
	*bright_tmp = rt_split((*tmp)[2], ',', 1);
	if (!*bright_tmp)
	{
		free_2arr(*tmp, *ret_tmp);
		return (0);
	}
	return (1);
}

int	init_read_light2(
		char **tmp,
		char ***ret_tmp,
		char ***bright_tmp,
		char ***color_tmp
)
{
	*color_tmp = rt_split(tmp[3], ',', 3);
	if (!*color_tmp)
	{
		free_3arr(tmp, *ret_tmp, *bright_tmp);
		return (0);
	}
	return (1);
}

int	init_fscanf_camera(
		char **tmp,
		char ***position_tmp,
		char ***fov_tmp,
		char ***normal_tmp
)
{
	*position_tmp = rt_split(tmp[1], ',', 3);
	if (!*position_tmp)
	{
		ft_free_arr(tmp);
		return (0);
	}
	*normal_tmp = rt_split(tmp[2], ',', 3);
	if (!*normal_tmp)
	{
		free_2arr(tmp, *position_tmp);
		return (0);
	}
	*fov_tmp = rt_split(tmp[3], ',', 1);
	if (!*fov_tmp)
	{
		free_3arr(tmp, *position_tmp, *normal_tmp);
		return (0);
	}
	return (1);
}

int	init_fscanf_plane(
		char **tmp,
		char ***centre_tmp,
		char ***normal_tmp,
		char ***color_tmp
)
{
	*centre_tmp = rt_split(tmp[1], ',', 3);
	if (!*centre_tmp)
	{
		ft_free_arr(tmp);
		return (0);
	}
	*normal_tmp = rt_split(tmp[2], ',', 3);
	if (!*normal_tmp)
	{
		free_2arr(tmp, *centre_tmp);
		return (0);
	}
	*color_tmp = rt_split(tmp[3], ',', 3);
	if (!*color_tmp)
	{
		free_3arr(tmp, *centre_tmp, *normal_tmp);
		return (0);
	}
	return (1);
}
