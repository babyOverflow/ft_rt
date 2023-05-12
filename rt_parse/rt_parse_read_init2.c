/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_read_init2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:30:28 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/12 15:20:17 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

int	init_fscanf_cylinder(
		char **tmp,
		char ***centre_tmp,
		char ***normal_tmp,
		char ***height_tmp
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
		free_2arr(tmp, *normal_tmp);
		return (0);
	}
	*height_tmp = rt_split(tmp[3], ',', 1);
	if (!*height_tmp)
	{
		free_3arr(tmp, *normal_tmp, *height_tmp);
		return (0);
	}
	return (1);
}

int	init_fscanf_cylinder2(
		char **tmp,
		char ***radius_tmp,
		char ***color_tmp
)
{
	*radius_tmp = rt_split(tmp[4], ',', 1);
	if (!*radius_tmp)
		return (0);
	*color_tmp = rt_split(tmp[5], ',', 3);
	if (!*color_tmp)
		return (0);
	return (1);
}

void	free_2arr(
	char **tmp1,
	char **tmp2
)
{
	ft_free_arr(tmp1);
	ft_free_arr(tmp2);
}

void	free_3arr(
	char **tmp1,
	char **tmp2,
	char **tmp3
)
{
	ft_free_arr(tmp1);
	ft_free_arr(tmp2);
	ft_free_arr(tmp3);
}

void	free_4arr(
	char **tmp1,
	char **tmp2,
	char **tmp3,
	char **tmp4
)
{
	ft_free_arr(tmp1);
	ft_free_arr(tmp2);
	ft_free_arr(tmp3);
	ft_free_arr(tmp4);
}
