/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:51:03 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 16:51:13 by seonghyk         ###   ########.fr       */
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
