/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:51:03 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/12 15:56:17 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_geo/rt_geo.h"
#include "rt_parse.h"

int	is_valid_colour(t_color *color)
{
	if (color->v[COLOR_IDX_RED] < 0 || color->v[COLOR_IDX_RED] > 1)
		return (0);
	if (color->v[COLOR_IDX_GREEN] < 0 || color->v[COLOR_IDX_GREEN] > 1)
		return (0);
	if (color->v[COLOR_IDX_BULE] < 0 || color->v[COLOR_IDX_BULE] > 1)
		return (0);
	if (color->v[COLOR_IDX_ALPHA] < 0 || color->v[COLOR_IDX_ALPHA] > 1)
		return (0);
	return (1);
}

int	is_valid_normal(t_vector3f *v)
{
	if (v->x < -1 || v->x > 1)
		return (0);
	if (v->y < -1 || v->y > 1)
		return (0);
	if (v->z < -1 || v->z > 1)
		return (0);
	if (v3fsize(v) == 0)
		return (0);
	return (1);
}

int	rt_split_inner(char *tmp, int j)
{
	int	flag;

	flag = 0;
	if (tmp[j] < '0' || tmp[j] > '9')
	{
		if (tmp[j] != '-' && tmp[j] != '+'
			&& tmp[j] != ',' && tmp[j] != '.')
			flag = 1;
		if (j > 0 && (tmp[j] == '-' || tmp[j] == '+')
			&& (tmp[j - 1] != ','))
			flag = 1;
		if (tmp[j] == '.' && (tmp[j + 1] < '0' || tmp[j + 1] > '9')
			&& tmp[j + 1] != '\n' && tmp[j + 1] != '\0')
			flag = 1;
		if ((tmp[j] == ',' || tmp[j] == '.')
			&& (tmp[j + 1] == '\n' || tmp[j + 1] == '\0'))
			flag = 1;
	}
	return (flag);
}

char	**rt_split(char *line, char c, int n)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = ft_split(line, c);
	i = 0;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j] != '\n' && tmp[i][j])
		{
			if (rt_split_inner(tmp[i], j))
			{
				ft_free_arr(tmp);
				return (NULL);
			}
		}
	}
	if (ft_cnt_arr(tmp) != n)
	{
		ft_free_arr(tmp);
		return (NULL);
	}
	return (tmp);
}
