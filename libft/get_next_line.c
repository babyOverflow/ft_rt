/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:03:08 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 21:05:33 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_info	*ft_lstnew(void)
{
	t_info	*ptr;

	ptr = (t_info *)malloc(sizeof(t_info));
	if (!ptr)
		return (0);
	ptr->rbyte = 0;
	ptr->str = 0;
	ptr->fd = -1;
	ptr->next = NULL;
	return (ptr);
}

t_info	*find_fd(int fd, t_info *head)
{
	t_info	*list;

	list = head;
	while (list->next)
	{
		list = list->next;
		if (list->fd == fd)
			return (list);
	}
	list->next = ft_lstnew();
	if (!(list->next))
		return (0);
	list = list->next;
	list->fd = fd;
	return (list);
}

void	lst_del(int fd, t_info *head)
{
	t_info	*list;
	t_info	*prev;

	list = head;
	prev = NULL;
	while (list->next)
	{
		if (list->next->fd == fd)
		{
			prev = list->next;
			list->next = prev->next;
			free(prev);
		}
		if (list->next)
			list = list->next;
	}
}

char	*ft_rbyte_less_zero(t_info **info, char **str, t_info *h)
{
	if ((*info)->rbyte < 0)
	{
		free((*info)->str);
		(*info)->str = NULL;
		lst_del((*info)->fd, h);
		return (0);
	}
	if ((*info)->rbyte == 0 && ((*info)->str) == 0)
	{
		lst_del((*info)->fd, h);
		return (0);
	}
	if ((*info)->rbyte == 0 && ((*info)->str) != 0)
	{
		(*str) = ft_strnjoin((*str), (*info)->str, ft_strlen((*info)->str));
		free((*info)->str);
		(*info)->str = 0;
		return ((*str));
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_info	head;
	size_t			point;
	char			*str;
	t_info			*info;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	str = 0;
	info = find_fd(fd, &head);
	if (!info)
		return (0);
	point = ft_findchr(info->str, '\n', ft_strlen(info->str));
	while (point == 0)
	{
		info->rbyte = read(fd, info->buf, BUFFER_SIZE);
		if (info->rbyte <= 0)
			return (ft_rbyte_less_zero(&info, &str, &head));
		info->buf[info->rbyte] = '\0';
		info->str = ft_strnjoin(info->str, info->buf, ft_strlen(info->buf));
		point = ft_findchr(info->str, '\n', ft_strlen(info->str));
	}
	str = ft_strnjoin(str, info->str, point);
	info->str = ft_str_cut_off(&info, point);
	return (str);
}
