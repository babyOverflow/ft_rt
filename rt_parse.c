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
	t_sphere *sphere = new_sphere(centre, radius);
	ret.v = sphere;
	ret.bounds = rt_sphere_get_bounds(sphere);
	return ret;
}

t_ambiant	read_ambiant(FILE* file)
{
	t_ambiant	ret;
	
	fscanf(file, "%f %d,%d,%d\n", &ret.bright, &ret.color.v[0], &ret.color.v[1], &ret.color.v[2]);
	return ret;
}

t_light	read_light(FILE* file)
{
	t_light ret;
	int	temp;

	fscanf(file, "%f,%f,%f %f %d,%d,%d", &ret.position.x, &ret.position.y, &ret.position.z, &ret.bright, &temp, &temp, &temp);
	return ret;
}

t_camera	read_camera(FILE* file)
{
	t_camera	ret;
	fscanf(file, "%f,%f,%f %f,%f,%f %d",
		&ret.position.x, &ret.position.y, &ret.position.z,
		&ret.normal.x, &ret.normal.y, &ret.normal.z, &ret.fov);
	return ret;
}

int	rt_parse_file(t_scene *scene, char *file_name)
{

	FILE* rt_file = fopen(file_name, "r");
	char *type;
	fscanf(rt_file, "%s ", type);
	if (strcmp(type, "A"))
	{
		t_ambiant a = read_ambiant(rt_file);
		scene->ambiant = a;
		// TODO
	}
	else if (strcmp(type, "C"))
	{
		t_camera c = read_camera(rt_file);
		scene->camera = c;
	}
	else if (strcmp(type, "L"))
	{
		t_light	l = read_light(rt_file);
		scene->light = l;
	}
	else if (strcmp(type, "sp"))
	{
		t_shape s = read_sphere(rt_file);
		rt_scene_append_shape(scene, s);
	}
	else if (strcmp(type, "pl"))
	{
		// TODO
	}
	else if (strcmp(type, "cy"))
	{
		// TODO
	}
	else
	{
		return 0;
	}
	return 1;
}