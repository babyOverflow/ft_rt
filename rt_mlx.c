/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:55:48 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/03 15:14:21 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rt.h"
#include "rt_math.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_data;



unsigned int	rt_mlx_sampler_get_color(const t_sampler *sampler, int x, int y)
{
	t_color			color;
	unsigned int	mlx_color;
	unsigned char	mlx_trgb[4];

	color = rt_sampler_get_color(sampler, x, y);
	mlx_trgb[0] = 255 * color.v[0];
	mlx_trgb[1] = 255 * color.v[1];
	mlx_trgb[2] = 255 * color.v[2];
	mlx_trgb[3] = 255 * color.v[3];
	mlx_color = *((unsigned int *)(mlx_trgb));
	return (mlx_color);
}

void	rt_mlx_print_image(void *renderer)
{
	const t_printer	*p = ((t_rt_renderer*)renderer)->printer;
	const t_sampler	*s = ((t_rt_renderer*)renderer)->sampler;
	t_data			*d;
	char			*dst;
	t_vector2i		pixel;

	d = p->data;
	pixel.y = 0;
	while (pixel.y < p->resolution_y)
	{
		pixel.x = 0;
		while (pixel.x < p->resolution_x)
		{
			dst = d->addr + (pixel.y * d->line_length
					+ pixel.x * (d->bit_per_pixel / 8));
			*(unsigned int *)(dst) = rt_mlx_sampler_get_color(
					s, pixel.x, pixel.y);
			++pixel.x;
		}
		++pixel.y;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	mlx_loop(d->mlx);
}

int	rt_mlx_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(
			data->mlx, resolution_x, resolution_y, "mini rt");
	data->img = mlx_new_image(data->mlx, resolution_x, resolution_y);
	data->addr = mlx_get_data_addr(
			data->img,
			&data->bit_per_pixel,
			&data->line_length,
			&data->endian);
	printer->data = data;
	printer->print_image = &rt_mlx_print_image;
	printer->resolution_x = resolution_x;
	printer->resolution_y = resolution_y;
	return (1);
}
