/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:46:10 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/15 14:35:35 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rt.h"
#include "rt_renderer.h"

int	rt_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y)
{
	printer->resolution_x = resolution_x;
	printer->resolution_y = resolution_y;
	return (1);
}

void	release_mlx_printer(t_printer *printer)
{
	t_data	*data;

	data = printer->data;
	if (printer->data != NULL)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data);
	}
}
