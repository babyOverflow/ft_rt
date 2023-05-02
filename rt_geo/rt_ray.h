#ifndef RT_RAY_H
# define RT_RAY_H

# include "../rt_math.h"

typedef struct s_ray {
	t_vector3f direction;
	t_vector3f origin;
} t_ray;

#endif //RT_RAY_H