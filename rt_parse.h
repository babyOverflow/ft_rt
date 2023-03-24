#ifndef RT_PARSE_H
# define RT_PARSE_H



int			check_files_name(int ac, char *av[]);
int			rt_parse_files(
				t_scene *scene,
				char *files[],
				int files_number);

#endif //RT_PARSE_H