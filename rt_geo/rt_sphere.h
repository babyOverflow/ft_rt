#ifndef RT_SPHERE_H
# define RT_SPHERE_H

# include "../rt_math.h"
# include "rt_bounds.h"

typedef struct s_shpere {

}	t_sphere;

t_sphere	*new_shpere(t_vector3f centre, float radius);
t_bounds	ret_sphrer_get_bounds(t_sphere *self);

#endif //RT_SPHERE_H