#ifndef RT_GEO_H
# define RT_GEO_H

# include <stdlib.h>
# include "rt_math.h"

typedef struct s_rgb {
	unsigned char v[3];
}	t_rgb;

enum e_shape_type {
	SPHERE
};

typedef int t_entity;

typedef struct s_ray {
	t_vector3f direction;
	t_vector3f origin;
} t_ray;

typedef struct s_bounds {
	t_vector3f point_max;
	t_vector3f point_min;
} t_bounds;

typedef struct s_shape {
	enum e_shape_type	type;
	void				*v;
	t_bounds			bounds;
	t_rgb				color;
} t_shape;

typedef struct s_world {
	t_shape *shapes;
	size_t elements_num;
	size_t elements_size;
} t_world;


int	ray_shape_intersect(const t_ray *ray, const t_shape *shape, float *t);
t_shape	*ray_world_intrsect(const t_ray *ray, const t_world *world);

#endif