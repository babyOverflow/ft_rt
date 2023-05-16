CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT

SRCS := rt.c \
	rt_math.c \
	rt_math_vec.c \
	rt_mlx.c \
	rt_scene.c \
	rt_sampler.c \
	rt_printer.c \
	rt_renderer.c \
	rt_geo/rt_camera.c \
	rt_geo/rt_sphere.c \
	rt_geo/rt_cylinder.c \
	rt_geo/rt_cylinder_inter.c \
	rt_geo/rt_plane.c \
	rt_parse/rt_parse.c \
	rt_parse/rt_parse_utils.c \
	rt_parse/rt_parse_read.c \
	rt_parse/rt_parse_read_shape.c \
	rt_parse/rt_parse_scanf.c \
	rt_parse/rt_parse_read_init.c \
	rt_parse/rt_parse_read_init2.c \
	rt_geo/rt_color.c \
	rt_geo/rt_world_inter.c \
	rt_geo/rt_world.c

OBJS = $(SRCS:.c=.o)
LIBC = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(LIBC)

clean:
	make clean -C libft
	rm -rf $(OBJS)
fclean:
	make clean
	make fclean -C libft
	rm -f $(NAME)
re:
	make fclean
	make all
.PHONY: clean fclean re all
