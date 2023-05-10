CC := clang

SRC := rt.c \
	rt_math.c \
	rt_math_vec.c \
	rt_mlx.c \
	rt_scene.c \
	rt_sampler.c \
	rt_renderer.c \
	rt_geo/rt_bounds_ray_intersect.c \
	rt_geo/rt_camera.c \
	rt_geo/rt_sphere.c \
	rt_geo/rt_cylinder.c \
	rt_geo/rt_plane.c \
	rt_parse/rt_parse.c \
	rt_parse/rt_parse_utils.c \
	rt_parse/rt_parse_read.c \
	rt_parse/rt_parse_read_shape.c \
	rt_parse/rt_parse_scanf.c \
	rt_geo/rt_color.c \
	rt_geo/rt_world_inter.c \
	rt_geo/rt_world.c

MLX_LINUX := minilibx-linux

CFLAGS_LINUX := -L./$(MLX_LINUX) -I./$(MLX_LINUX) -lXext -lX11

CFLAGS_MAC := -lmlx -framework OpenGL -framework AppKit


CFLAGS := -L./libft -lft $(CFLAGS_MAC) -L/usr/lib -lm -lz -I/usr/include

all : $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(SRC) $(CFLAGS) -lmlx  -g -o rt 
