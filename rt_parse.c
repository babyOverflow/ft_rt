#include "rt_parse.h"
#include <stdio.h>
#include <string.h>

int	check_files_name(int ac, char **av)
{
	return 1;
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
		// TODO
	}
	else
	{
		// TODO
	}
	return 1;
}