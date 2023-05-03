/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:45:12 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:04 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_word(char const *s, char c)
{
	size_t	i;
	int		cnt_word;

	i = 1;
	cnt_word = 0;
	while (i < (size_t)ft_strlen(s) + 1)
	{
		if ((s[i] == c && (s[i - 1] != c)) || (s[i] == '\0' && s[i - 1] != c))
			cnt_word++;
		i++;
	}
	return (cnt_word);
}

static void	free_ptr(char **ptr, size_t ptr_index)
{
	size_t	i;

	i = 0;
	while (i < ptr_index)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	**ft_put_ptr(char const *s, char c, char **ptr, size_t i)
{
	int		p;
	size_t	ptr_index;

	p = 0;
	ptr_index = 0;
	while ((int)i < (int)ft_strlen(s) + 1)
	{
		if ((i > 0 && s[i] == c && s[i - 1] != c)
			|| (i > 0 && s[i] == '\0' && s[i - 1] != c))
		{
			ptr[ptr_index] = (char *)malloc(i - p + 1);
			if (!ptr[ptr_index])
			{
				free_ptr(ptr, ptr_index);
				return (0);
			}
			ft_strlcpy(ptr[ptr_index++], s + p, i - p + 1);
		}
		if (s[i] == c)
			p = i + 1;
		i++;
	}
	ptr[ptr_index] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;

	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (ft_cnt_word(s, c) + 1));
	if (!ptr)
		return (0);
	ptr = ft_put_ptr(s, c, ptr, i);
	return (ptr);
}
