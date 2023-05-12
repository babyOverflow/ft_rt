/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:15:02 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 22:53:34 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "../rt_geo/rt_geo.h"
#include "../rt_math.h"
#include <string.h>
#include <float.h>
#include <fcntl.h>

int	check_files_name(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3) == 0)
		return (1);
	return (0);
}

char	*nl2null(char **tmp)
{
	int	i;

	i = -1;
	while ((*tmp)[++i])
	{
		if ((*tmp)[i] == '\n')
		{
			(*tmp)[i] = '\0';
			break ;
		}
	}
	return (*tmp);
}

char	*gnl(int rt_file)
{
	char	*tmp;

	tmp = get_next_line(rt_file);
	tmp = nl2null(&tmp);
	return (tmp);
}

int	rt_parse_file(t_scene *scene, char *file_name)
{
	int		rt_file;
	char	*line;
	int		is_success;

	rt_file = open(file_name, O_RDONLY);
	line = get_next_line(rt_file);
	while (line)
	{
		if (ft_strncmp(line, "A", 1) == 0)
			is_success = read_ambiant(scene, line);
		else if (ft_strncmp(line, "C", 1) == 0)
			is_success = read_camera(scene, line);
		else if (ft_strncmp(line, "L", 1) == 0)
			is_success = read_light(scene, line);
		else if (line[0] == '\n')
			is_success = 1;
		else
			is_success = read_shape(scene, line);
		free(line);
		if (!is_success)
			return (0);
		line = get_next_line(rt_file);
	}
	return (1);
}
