/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:17:49 by seonghyk          #+#    #+#             */
/*   Updated: 2023/05/10 17:40:42 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# include "../rt_renderer.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

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

int		check_files_name(int ac, char *av[]);
int		rt_parse_file(t_scene *scene, char *file_name);
void	fscanf_cylinder(t_read_cylinder *rcy, char **tmp);
void	fscanf_sphere(t_read_sphere *rsp, char **tmp);
void	fscanf_camera(t_read_camera *camera, t_camera *ret, char **tmp);
void	fscanf_plane(t_read_plane *rpl, char **tmp);

int		is_valid_colour(t_color *color);
int		is_valid_normal(t_vector3f *v);

int		read_shape(t_scene *scene, char *line);
int		read_cylinder(t_scene *scene, char *line);
int		read_sphere(t_scene *scene, char *line);
int		read_plane(t_scene *scene, char *line);
int		read_ambiant(t_scene *scene, char *line);
int		read_light(t_scene *scene, char *line);
int		read_camera(t_scene *scene, char *line);
#endif //RT_PARSE_H
