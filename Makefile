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

MLX := minilibx-linux

CFLAGS := -L./$(MLX) -I./$(MLX) -L/usr/lib  -lXext -lX11 -lm -lz -I/usr/include

all : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -g -lmlx -o rt
