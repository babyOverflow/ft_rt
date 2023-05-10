/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_geo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:53:47 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 17:34:17 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GEO_H
# define RT_GEO_H

# include <stdlib.h>
# include <math.h>

# include "../rt_math.h"
# include "rt_ray.h"
# include "rt_bounds.h"
# include "rt_sphere.h"
# include "rt_cylinder.h"
# include "rt_plane.h"

# define COLOR_IDX_ALPHA 3
# define COLOR_IDX_RED 2
# define COLOR_IDX_GREEN 1
# define COLOR_IDX_BULE 0

typedef struct s_color {
	float	v[4];
}	t_color;

enum e_shape_type {
	SPHERE,
	CYLINDER,
	PLANE
};

typedef int	t_entity;

typedef struct s_shape {
	enum e_shape_type	type;
	void				*v;
	t_bounds			bounds;
	t_color				color;
}	t_shape;

typedef struct s_world {
	t_shape	*shapes;
	size_t	elements_num;
	size_t	elements_size;
}	t_world;

t_color		color_add(t_color *a, t_color *b);
t_color		color_clip(t_color *c);
t_color		mul_color_s1f(t_color *c, float s);
t_color	create_color(int red, int green, int blue);

int			ray_shape_intersect(
				const t_ray *ray,
				const t_shape *shape,
				float *t,
				t_intersection *inter);
t_shape		*ray_world_intersect(
				const t_ray *ray,
				const t_world *world,
				t_intersection *inter);
int			ray_world_intersect_b(
				const t_ray *ray,
				const t_world *world,
				t_shape *except);
int			rt_world_append_shape(t_world *world, t_shape s);
t_world		*create_world(void);
void		release_world(t_world *world);

t_matrix4f	perspective(float fov, float n, float f);
t_matrix4f	perspective_inverse(float fov, float n, float f);
t_matrix4f	lookat(
				t_vector3f *normal,
				t_vector3f *up);

#endif
