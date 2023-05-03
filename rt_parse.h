#ifndef RT_PARSE_H
# define RT_PARSE_H

# include "rt_renderer.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_read_cylinder
{
	t_vector3f	centre;
	t_vector3f	normal;
	float		radius;
	float		height;
	int			r;
	int			g;
	int			b;
}	t_read_cylinder;

typedef struct s_read_sphere
{
	t_vector3f	centre;
	float		radius;
	int			r;
	int			g;
	int			b;
}	t_read_sphere;

typedef struct s_read_light
{
	int	r;
	int	g;
	int	b;
}	t_read_light;

typedef struct s_read_camera
{
	t_matrix4f	projection_inverse;
	t_matrix4f	lookat_;
}	t_read_camera;

typedef struct s_read_plane
{
	t_vector3f	centre;
	t_vector3f	normal;
	int			r;
	int			g;
	int			b;
}	t_read_plane;

typedef struct s_type
{
	t_ambiant	a;
	t_camera	c;
	t_light		l;
	t_shape		s;
}	t_type;

int			check_files_name(int ac, char *av[]);
int			rt_parse_file(t_scene *scene, char *file_name);
void		fscanf_cylinder(t_read_cylinder *rcy, char **tmp);
void		fscanf_sphere(t_read_sphere *rsp, char **tmp);
void		fscanf_camera(t_read_camera *camera, t_camera *ret, char **tmp);
void	fscanf_plane(t_read_plane *rpl, char **tmp);
t_shape		read_cylinder(char *line);
t_shape		read_sphere(char *line);
t_ambiant	read_ambiant(char *line);
t_light		read_light(char *line);
t_camera	read_camera(char *line);
t_shape		read_plane(char *line);
#endif //RT_PARSE_H
