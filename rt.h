/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:30 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/15 05:05:25 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "rt_geo/rt_geo.h"
# include "rt_renderer.h"
# include "rt_parse/rt_parse.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int			rt_mlx_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y);
t_sampler	create_default_sampler(
				int resolution_x,
				int resolution_y);
int			rt_init_renderer(
				t_rt_renderer *renderer,
				t_printer *printer,
				t_sampler *sampler);
int			rt_render_scenes(
				t_rt_renderer *renderer,
				t_scene *scenes);

void		rt_exit_with_msg(char *msg);

#endif
