#include "rt_parse.h"
#include "rt_geo/rt_geo.h"
#include "rt_math.h"
#include <stdio.h>
#include <string.h>
#include <float.h>

int	check_files_name(int ac, char **av)
{
	if (ac != 2)
		return 0;
	return 1;
}

t_shape	read_cylinder(FILE* file)
{
	t_shape		ret;
	t_vector3f	centre;
	t_vector3f	normal;
	float		radius;
	float		height;
	int	r, g, b;

	fscanf(file, "%f,%f,%f ",
		&(centre.x), &(centre.y), &(centre.z));
	fscanf(file, "%f,%f,%f ",
		&(normal.x), &(normal.y), &(normal.z));
	fscanf(file, "%f %f %d,%d,%d\n",
		&height,
		&radius,
		&r, &g, &b);
	ret.type = CYLINDER;
	ret.color.v[2] = r;
	ret.color.v[1] = g;
	ret.color.v[0] = b;
	t_cylinder *cy = new_cylinder(centre, normal, radius, height);
	ret.v = cy;
	// ret.bounds = rt_cylinder_get_bounds(cy);
	return ret;
}

t_shape	read_sphere(FILE* file)
{
	t_shape		ret;
	t_vector3f	centre;
	float		radius;
	int	r, g, b;

	fscanf(file, "%f,%f,%f ",
		&(centre.x), &(centre.y), &(centre.z));
	fscanf(file, "%f %d,%d,%d\n",
		&radius,
		&r, &g, &b);
	ret.type = SPHERE;
	ret.color.v[2] = r;
	ret.color.v[1] = g;
	ret.color.v[0] = b;
	t_sphere *sphere = new_sphere(centre, radius);
	ret.v = sphere;
	ret.bounds = rt_sphere_get_bounds(sphere);
	return ret;
}

t_ambiant	read_ambiant(FILE* file)
{
	t_ambiant	ret;
	int			r, g, b;
	
	fscanf(file, "%f %d,%d,%d\n", &ret.bright, &r, &g, &b);
	ret.color.v[2] = r;
	ret.color.v[1] = g;
	ret.color.v[0] = b;
	return ret;
}

t_light	read_light(FILE* file)
{
	t_light ret;
	int	temp;
	int	temp2;
	int	temp3;

	fscanf(file, "%f,%f,%f %f %d,%d,%d\n",
		&ret.position.x, &ret.position.y, &ret.position.z,
		&ret.bright, &temp, &temp2, &temp3);
	return ret;
}

t_camera	read_camera(FILE* file)
{
	t_camera	ret;
	t_matrix4f	projection_inverse;
	t_matrix4f	lookat_;

	fscanf(file, "%f,%f,%f %f,%f,%f %d\n",
		&ret.position.x, &ret.position.y, &ret.position.z,
		&ret.normal.x, &ret.normal.y, &ret.normal.z, &ret.fov);
	ret.camera2world = lookat(&(ret.position), &(ret.normal), &(t_vector3f){0, 1, 0});
	ret.screen2camera = perspective_inverse(ret.fov, 0, FLT_MAX);
	return ret;
}

int	rt_parse_file(t_scene *scene, char *file_name)
{

	FILE* rt_file = fopen(file_name, "r");
	char type[3];
	while ( fscanf(rt_file, "%s ", type) == 1)
	{
		if (strcmp(type, "A") == 0)
		{
			t_ambiant a = read_ambiant(rt_file);
			scene->ambiant = a;
			// TODO
		}
		else if (strcmp(type, "C") == 0)
		{
			t_camera c = read_camera(rt_file);
			scene->camera = c;
		}
		else if (strcmp(type, "L") == 0)
		{
			t_light	l = read_light(rt_file);
			scene->light = l;
		}
		else if (strcmp(type, "sp") == 0)
		{
			t_shape s = read_sphere(rt_file);
			rt_scene_append_shape(scene, s);
		}
		else if (strcmp(type, "pl") == 0)
		{
			// TODO
		}
		else if (strcmp(type, "cy") == 0)
		{
			t_shape	s = read_sphere(rt_file);
			rt_scene_append_shape(scene, s);
		}
		else
		{
			return 0;
		}
	}
	return 1;
}