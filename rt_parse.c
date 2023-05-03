/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:15:02 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 18:02:36 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_geo/rt_geo.h"
#include "rt_math.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <fcntl.h>

int	check_files_name(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3) == 0)
		return (1);
	return (0);
}

int	rt_parse_file(t_scene *scene, char *file_name)
{
	int		rt_file;
	char	*line;
	char	type[3];
	t_type	t;

	rt_file = open(file_name, O_RDONLY);
	line = get_next_line(rt_file);
	while (line)
	{
		if (ft_strncmp(line, "A", 1) == 0)
		{
			t.a = read_ambiant(line);
			scene->ambiant = t.a;
		}
		else if (ft_strncmp(line, "C", 1) == 0)
		{
			t.c = read_camera(line);
			scene->camera = t.c;
		}
		else if (ft_strncmp(line, "L", 1) == 0)
		{
			t.l = read_light(line);
			scene->light = t.l;
		}
		else if (ft_strncmp(line, "sp", 2) == 0)
		{
			t.s = read_sphere(line);
			rt_scene_append_shape(scene, t.s);
		}
		else if (ft_strncmp(line, "pl", 2) == 0)
		{
			t.s = read_plane(line);
			rt_scene_append_shape(scene, t.s);
		}
		else if (ft_strncmp(line, "cy", 2) == 0)
		{
			t.s = read_cylinder(line);
			rt_scene_append_shape(scene, t.s);
		}
		else if (line[0] == '\n')
		{
			
		}
		else
			return (0);
		free(line);
		line = get_next_line(rt_file);
	}
	return (1);
}
