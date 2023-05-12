/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:20:11 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/11 20:20:26 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cnt_arr(char **arr)
{
	int	cnt;

	cnt = 0;
	if (arr == NULL)
		return (cnt);
	while (arr[cnt])
		cnt++;
	return (cnt);
}
