#include "rt_geo.h"

void	rgb_set_red_u8(t_color *self, unsigned char red)
{
	self->v[COLOR_IDX_RED] = (float)red / 255.0;
}
void	rgb_set_green_u8(t_color *self, unsigned char green)
{
	self->v[COLOR_IDX_GREEN] = (float)green / 255.0;
}
void	rgb_set_blue_u8(t_color *self, unsigned char blue)
{
	self->v[COLOR_IDX_BULE] = (float)blue / 255.0;
}

t_color	create_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color	ret;

	ret.v[COLOR_IDX_RED] = (float)red / 255.0;
	ret.v[COLOR_IDX_BULE] = (float)blue / 255.0;
	ret.v[COLOR_IDX_GREEN] = (float)green / 255.0;
	ret.v[COLOR_IDX_ALPHA] = 0;
	return (ret);
}