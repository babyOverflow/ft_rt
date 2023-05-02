#include <math.h>
#include "rt_math.h"

t_vector3f	prouct_m4fv3f(const t_matrix4f *mat, const t_vector3f *vec)
{
	return (t_vector3f){
		mat->v[0][0] * vec->x + mat->v[0][1] * vec->y + mat->v[0][2] * vec->z + mat->v[0][3] * 1,
		mat->v[1][0] * vec->x + mat->v[1][1] * vec->y + mat->v[1][2] * vec->z + mat->v[1][3] * 1,
		mat->v[2][0] * vec->x + mat->v[2][1] * vec->y + mat->v[2][2] * vec->z + mat->v[2][3] * 1,
	};
}

t_vector3f	v3fnag(const t_vector3f *v)
{
	return (t_vector3f)
	{
		.x = -v->x,
		.y = -v->y,
		.z = -v->z,
	};
}

float	v3fdot(const t_vector3f *v, const t_vector3f *u)
{
	float	ret;

	ret	= v->x * u->x +
		v->y * u->y +
		v->z * u->z;
	return (ret);
}

t_vector3f	mul_v3fs1f(const t_vector3f *v, float s)
{
	t_vector3f	ret;

	ret.x = v->x * s;
	ret.y = v->y * s;
	ret.z = v->z * s;
	return (ret);
}

t_vector3f	v3fadd(const t_vector3f *v, const t_vector3f *u)
{
	t_vector3f	ret;

	ret.x = v->x + u->x;
	ret.y = v->y + u->y;
	ret.z = v->z + u->z;
	return (ret);
}

t_vector3f	v3fsub(const t_vector3f *v, const t_vector3f *u)
{
	t_vector3f	ret;

	ret.x = v->x - u->x;
	ret.y = v->y - u->y;
	ret.z = v->z - u->z;
	return (ret);
}

t_vector3f	v3fcross(const t_vector3f *v, const t_vector3f *u)
{
	t_vector3f	ret;

	ret.x = (v->y * u->z) - (v->z * u->y);
	ret.y = (v->z * u->x) - (v->x * u->z);
	ret.z = (v->x * u->y) - (v->y * u->x);
	return (ret);
}

t_vector3f	v3fnormalize(const t_vector3f *v)
{
	t_vector3f	ret;
	float		dot;
	float		len;

	dot = v3fdot(v, v);
	len = sqrt(dot);
	ret = (t_vector3f){
		v->x / len,
		v->y / len,
		v->z / len,
	};
	return (ret);
}

int	quadratic(t_vector3f abc, float *t0, float *t1)
{
	double	discrim;
	double	q;

	discrim = abc.y * abc.y - 4 * abc.x * abc.z;
	if (discrim < 0)
		return 0;
	discrim = sqrt(discrim);
	if (abc.y < 0)
		q = -.5 * (abc.y - discrim);
	else
		q = -.5 * (abc.y + discrim);
	*t0 = q / abc.x;
	*t1 = abc.z / q;
	if (*t0 > *t1)
	{
		discrim = *t0;
		*t0 = *t1;
		*t1 = discrim;
	}
	return 1;
}
