#ifndef RT_CYLINDER_H
# define RT_CYLINDER_H

# include "../rt_math.h"
# include "rt_bounds.h"


typedef struct s_cylinder {
	t_vector3f	centre;
	t_vector3f	normal;
	float		 diameter;;
	float		height;
}	t_cylinder;

t_cylinder	*new_cylinder(
				t_vector3f centre,
				t_vector3f normal,
				float height,
				float diameter);
t_bounds	rt_cylinder_get_bounds(t_cylinder *self);
int			ray_cylinder_intersect(
				const t_ray *ray,
				const t_cylinder *shape,
				float *t,
				t_intersection *inter);


#endif //RT_SPHERE_H
