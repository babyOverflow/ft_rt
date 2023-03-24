#ifndef RT_BOUNDS_H
# define RT_BOUNDS_H

# include "../rt_math.h"
# include "rt_ray.h"

typedef struct s_bounds {
	t_vector3f point_max;
	t_vector3f point_min;
} t_bounds;

int	rt_bounds_ray_intersect(t_bounds *b, t_ray *r);

#endif