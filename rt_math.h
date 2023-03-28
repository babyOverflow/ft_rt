#ifndef RT_MATH_H
# define RT_MATH_H

# define PI 3.141592

typedef struct s_vector3f {
	float	x;
	float	y;
	float	z;
} t_vector3f;

typedef struct s_point3f {
	float	x;
	float	y;
	float	z;
} t_point3f;

typedef struct s_matrix4f {
	float	v[4][4];
}	t_matrix4f;

#endif