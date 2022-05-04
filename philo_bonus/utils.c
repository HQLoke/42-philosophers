/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:49 by hloke             #+#    #+#             */
/*   Updated: 2022/05/04 16:20:53 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
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

void	print_action(t_rules *r, int philo_id, int action)
{	
	sem_wait(r->message);
	if (action == GRAB_FORK)
		printf(GRN "%li %i has taken a fork", timestamp_ms(), philo_id + 1);
	else if (action == EATING)
		printf(MAG "%li %i is eating", timestamp_ms(), philo_id + 1);
	else if (action == THINKING)
		printf(CYN "%li %i is thinking", timestamp_ms(), philo_id + 1);
	else if (action == SLEEPING)
		printf(YEL "%li %i is sleeping", timestamp_ms(), philo_id + 1);
	printf("\n" RESET);
	sem_post(r->message);
}

//* usleep is not accurate, this function splits into parts by using usleep(200)
//* argument time is in milliseconds, requires conversion into microseconds
void	smart_sleep(int time_in_ms)
{
	long	begin_t;

	begin_t = timestamp_ms();
	while (true)
	{
		if ((timestamp_ms() - begin_t) >= (long)time_in_ms)
			break ;
		usleep (200);
	}
}

//* returns current time in milliseconds
long	timestamp_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//* returns the difference between past and future time
int	time_diff(long new_time, long old_time)
{
	return (new_time - old_time);
}
