#ifndef PLANE_H
# define PLANE_H

# include "../rt_math.h"
# include "rt_bounds.h"

typedef struct s_plane {
	t_vector3f	centre;
	t_vector3f	normal;
}	t_plane;

t_plane		*new_plane(t_vector3f centre, t_vector3f normal);
t_bounds	rt_plane_get_bounds(t_plane *self);
int			ray_plane_intersect(
				const t_ray *ray,
				const t_plane *plane,
				float *t,
				t_intersection *inter);

#endif //PLANE_H
