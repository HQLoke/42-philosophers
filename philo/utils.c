/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:49 by hloke             #+#    #+#             */
/*   Updated: 2022/04/22 09:22:49 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_atoi(const char *str)
{
	long	sum;
	long	sign;

	sum = 0;
	sign = 1;
	while ((*str == '\n') || (*str == '\t') || (*str == '\v')
		|| (*str == ' ') || (*str == '\f') || (*str == '\r'))
		str += 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str += 1;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str += 1;
	}
	sum = sum * sign;
	if (sum > 2147483647 || sum < -2147483648)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)sum);
}
