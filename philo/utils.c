/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:49 by hloke             #+#    #+#             */
/*   Updated: 2022/04/24 18:21:15 by hloke            ###   ########.fr       */
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

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->rules->message);
	if (action == TAKE_FORK)
		printf("%li %3i has taken a fork.\n", get_time_in_ms(), philo->id);
	else if (action == EATING)
		printf("%li %3i is eating.\n", get_time_in_ms(), philo->id);
	else if (action == THINKING)
		printf("%li %3i is thinking.\n", get_time_in_ms(), philo->id);
	else if (action == SLEEPING)
		printf("%li %3i is sleeping.\n", get_time_in_ms(), philo->id);
	else if (action == DIED)
		printf("%li %3i has died.\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->rules->message);
}

void	smart_sleep(void)
{
	// while ()
	// {
	// 	if ()
	// 		break;
		
	// }
}
