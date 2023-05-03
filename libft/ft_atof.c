/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycheon <seycheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:30:26 by seycheon          #+#    #+#             */
/*   Updated: 2023/05/03 15:07:05 by seycheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	below_zero(char *str, double *num)
{
	int	i;

	i = 1;
	if (*str == '.')
	{
		str++;
		while (*str)
		{
			*num += (*str - '0') * pow(0.1, i);
			str++;
			i++;
		}
	}
}

float	ft_atof(char *str)
{
	int		sign;
	double	num;

	sign = 1;
	num = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	below_zero(str, &num);
	return (sign * num);
}

