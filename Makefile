CC := gcc

SRC := rt.c \
	rt_math.c \
	rt_mlx.c \
	rt_parse.c \
	rt_renderer.c \
	rt_geo/rt_bounds_ray_intersect.c \
	rt_geo/rt_camera.c \
	rt_geo/rt_sphere.c \
	rt_geo/rt_world.c

all : $(SRC)
	$(CC) $(SRC) -g -lmlx -o rt
