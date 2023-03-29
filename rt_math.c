#include "rt_math.h"

t_vector3f	prouct_m4fv3f(const t_matrix4f *mat, const t_vector3f *vec)
{
	return (t_vector3f){
		mat->v[0][0] * vec->x + mat->v[0][1] * vec->y + mat->v[0][2] * vec->z,
		mat->v[1][0] * vec->x + mat->v[1][1] * vec->y + mat->v[1][2] * vec->z,
		mat->v[2][0] * vec->x + mat->v[2][1] * vec->y + mat->v[1][2] * vec->z,
	};
}
