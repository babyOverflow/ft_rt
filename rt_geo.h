#include <stdlib.h>
#include "rt_math.h"

typedef int t_entity;

typedef struct s_ray {
	t_vector3f direction;
	t_point3f origin;
} t_ray;

typedef struct s_bounds {
	t_point3f point_max;
	t_point3f point_min;
} t_bounds;

typedef struct s_shape {
	t_bounds bounds;
} t_shape;

typedef struct s_world {
	t_shape *shapes;
	size_t elements_num;
	size_t elements_size;
} t_world;
