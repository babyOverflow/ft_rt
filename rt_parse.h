#ifndef RT_PARSE_H
# define RT_PARSE_H

# include "rt_renderer.h"

int	check_files_name(int ac, char *av[]);
int	rt_parse_file(t_scene *scene, char *file_name);

#endif //RT_PARSE_H