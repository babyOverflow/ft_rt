#include "rt_parse.h"
#include <stdio.h>
#include <string.h>

int	check_files_name(int ac, char **av)
{
	return 1;
}

t_shape	read_sphere(FILE* file)
{
	t_shape		ret;
	t_vector3f	centre;
	float		radius;

	ret.type = SPHERE;
	fscanf(file, "%f,%f,%f %f %d,%d,%d\n",
		&centre.x, &centre.y, &centre.z, &radius,
		&ret.color.v[0], &ret.color.v[1], &ret.color.v[2]);
	t_sphere *sphere = new_shpere(centre, radius);
	ret.v = sphere;
	ret.bounds = ret_sphrer_get_bounds(sphere);
	return ret;
}

int	rt_parse_file(t_scene *scene, char *file)
{

	FILE* rt_file = fopen(file, "r");
	char *type;
	fscanf(rt_file, "%s ", type);
	if (strcmp(type, "A"))
	{
		// TODO
	}
	else if (strcmp(type, "C"))
	{
		// TODO
	}
	else if (strcmp(type, "sp"))
	{
		t_shape s = read_sphere(rt_file);
		rt_scene_append_shape(scene, s);
	}
	else
	{
		// TODO
	}
	return 1;
}