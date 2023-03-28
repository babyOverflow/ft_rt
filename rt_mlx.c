#include <mlx.h>
#include "rt.h"

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
	return (unsigned int)rt_sampler_get_color(sampler, x, y).v;
}

void	rt_mlx_print_image(void *renderer)
{
	const t_printer	*p = ((t_rt_renderer*)renderer)->printer;
	const t_sampler *s = ((t_rt_renderer*)renderer)->sampler;
	t_data			*d = p->data;

	for (int y = 0; y < p->resolution_y; ++y)
	{
		for (int x = 0; x < p->resolution_x; ++x)
		{
			*(d->addr + (y * d->line_length + (x * d->bit_per_pixel / 8))) = 
				rt_mlx_sampler_get_color(s, x, y);
		}
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
}

int			rt_mlx_init_printer(
				t_printer *printer,
				int resolution_x,
				int resolution_y)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(mlx, resolution_x, resolution_y, "mini rt");
	data->img = mlx_new_image(mlx, resolution_x, resolution_y);
	data->addr = mlx_get_data_addr(
		data->img,
		&data->bit_per_pixel,
		&data->line_length,
		&data->endian);
	printer->data = data;
	printer->print_image = &rt_mlx_print_image;
	return (1);
}
