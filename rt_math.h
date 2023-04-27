#ifndef RT_MATH_H
# define RT_MATH_H

# define PI 3.141592

typedef struct s_vector3f {
	float	x;
	float	y;
	float	z;
} t_vector3f;

typedef struct s_vector4f {
	float	x;
	float	y;
	float	z;
	float	w;
} t_vector4f;

typedef struct s_vector2i {
	int	x;
	int	y;
}	t_vector2i;

typedef struct s_point3f {
	float	x;
	float	y;
	float	z;
} t_point3f;

typedef struct s_matrix4f {
	float	v[4][4];
}	t_matrix4f;

t_vector3f	prouct_m4fv3f(const t_matrix4f *mat, const t_vector3f *vec);
int	quadratic(t_vector3f abc, float *t0, float *t1);
float	v3fdot(t_vector3f *v, t_vector3f *u);
t_vector3f	v3fnormalize(const t_vector3f *v);
t_vector3f	v3fcross(const t_vector3f *v, const t_vector3f *u);
t_vector3f	v3fnag(t_vector3f *v);
t_matrix4f	m4frotation(float x, float y, float z);

#endif