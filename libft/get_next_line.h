/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:44:32 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 16:50:15 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFFER_SIZE 1024

typedef struct s_info
{
	int				rbyte;
	char			*str;
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_info	*next;
}	t_info;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_findchr(char *str, char c, size_t n);
char	*ft_str_cut_off(t_info **info, size_t n);
char	*ft_strnjoin(char *s1, char *s2, size_t n);
char	*ft_rbyte_less_zero(t_info **info, char **str, t_info *h);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# else
#  if BUFFER_SIZE < 1
#   error INVALID BUFFER_SIZE!
#  endif
# endif

#endif
