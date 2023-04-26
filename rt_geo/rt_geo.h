#ifndef RT_GEO_H
# define RT_GEO_H

# include <stdlib.h>
# include <math.h>

# include "../rt_math.h"
# include "rt_ray.h"
# include "rt_bounds.h"
# include "rt_sphere.h"

typedef struct s_rgb {
	unsigned char v[4];
}	t_rgb;

enum e_shape_type {
	SPHERE
};

typedef int t_entity;

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


int	ray_shape_intersect(
			const t_ray *ray,
			const t_shape *shape,
			float *t,
			t_intersection *inter);
t_shape	*ray_world_intersect(
				const t_ray *ray,
				const t_world *world,
				float *t,
				t_intersection *inter);
int	ray_world_intersect_b(const t_ray *ray, const t_world *world, t_shape *except);
int		rt_world_append_shape(t_world* world, t_shape s);
t_world	*create_world();

t_matrix4f	perspective(float fov, float n, float f);
t_matrix4f	perspective_inverse(float fov, float n, float f);
t_matrix4f	lookat(
				t_vector3f *pos,
				t_vector3f *normal,
				t_vector3f *up);

#endif
