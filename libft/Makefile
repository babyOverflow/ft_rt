# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:41:06 by seycheon          #+#    #+#              #
#    Updated: 2023/05/11 20:20:40 by seycheon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atof.c ft_atoi.c ft_free_arr.c ft_memset.c ft_split.c ft_strncmp.c \
		ft_strlcpy.c get_next_line.c get_next_line_utils.c  ft_strlen.c \
		ft_cnt_arr.c

OBJS = $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

all: $(NAME)

$(NAME): $(OBJS_FILES)
	ar rc $(NAME) $^

.c.o:
	$(CC) $(CFLAGS) -g -o $@ $^

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
