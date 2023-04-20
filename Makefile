CC := clang

SRC := rt.c \
	rt_math.c \
	rt_mlx.c \
	rt_parse.c \
	rt_renderer.c \
	rt_geo/rt_bounds_ray_intersect.c \
	rt_geo/rt_camera.c \
	rt_geo/rt_sphere.c \
	rt_geo/rt_world.c

MLX_LINUX := minilibx-linux

CFLAGS_LINUX := -L./$(MLX_LINUX) -I./$(MLX_LINUX) -lXext -lX11

CFLAGS_MAC := -Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS := $(CFLAGS_MAC) -L/usr/lib   -lm -lz -I/usr/include

all : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -g -lmlx -o rt
