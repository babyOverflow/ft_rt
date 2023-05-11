/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:46:10 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/11 12:08:03 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	release_printer(t_printer *printer)
{
	if (printer->data != NULL)
		free(printer->data);
	printer->data = NULL;
}
