#include "rt_geo.h"

t_matrix4f	perspective(float fov, float n, float f)
{
	t_matrix4f	ret;
	const float	tmp = 1 / tanf((fov * PI / 180) / 2);

	ret = (t_matrix4f){
		tmp, 0, 0, 0,
		0, tmp, 0, 0,
		0, 0,  f / (f - n), -f * n / (f - n),
		0, 0, 1, 0
	};
	return (ret);
}
