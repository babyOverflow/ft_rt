/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:25:21 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 20:20:34 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
void	*ft_memset(void	*b, int c, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
float	ft_atof(char *str);
int		ft_atoi(char *str);
char	*get_next_line(int fd);
void	ft_free_arr(char **arr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_cnt_arr(char **arr);
#endif
