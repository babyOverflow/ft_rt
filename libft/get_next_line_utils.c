/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:51:20 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 16:52:23 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

size_t	ft_findchr(char *str, char c, size_t n)
{
	size_t	i;

	i = 0;
	if (str == 0 || n == 0)
		return (0);
	while (i < n)
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*ptr;

	if (s1 == 0)
	{
		ptr = (char *)malloc(n + 1);
		if (!ptr)
			return (0);
		ft_strlcpy(&ptr[0], s2, n + 1);
		ptr[n] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(ft_strlen(s1) + n + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(&ptr[0], s1, ft_strlen(s1) + 1);
	ft_strlcpy(&ptr[ft_strlen(s1)], s2, n + 1);
	ptr[ft_strlen(s1) + n] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}

char	*ft_str_cut_off(t_info **info, size_t n)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (ft_strlen((*info)->str) == (int)n)
	{
		free((*info)->str);
		(*info)->str = NULL;
		if ((*info)->rbyte == 0)
			free(*info);
		return (0);
	}
	copy = malloc(ft_strlen((*info)->str) - n + 1);
	if (!copy)
		return (0);
	while (i < ft_strlen((*info)->str) - n)
	{
		copy[i] = (*info)->str[i + n];
		i++;
	}
	copy[i] = '\0';
	free((*info)->str);
	(*info)->str = NULL;
	return (copy);
}
