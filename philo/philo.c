/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:19:50 by hloke             #+#    #+#             */
/*   Updated: 2022/04/20 14:57:36 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* returns current time in milliseconds
//* also check if gettimeofday returns -1
//* module 100000 is to remove redundant digits in the front
long	get_time_in_ms(void)
{
	struct timeval	current_time;
	long			retval;
	
	if (gettimeofday(&current_time, NULL) == -1)
		printf("error: get_time_in_ms: gettimeofday\n");
	retval = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (retval % 10000000);
}

//* since usleep takes in microseconds as argument
//* sleep_in_ms takes in milliseconds from argv and convert to microseconds
//* also check if usleep returns -1
void	sleep_in_ms(int millisec)
{
	if (usleep(millisec * 1000) == -1)
		printf("error: sleep_in_ms: usleep\n");
}

void	grab_forks(void)
{
	pthread_mutex_lock();
	printf("%li\n", get_time_in_ms());
	sleep_in_ms(200);

	pthread_mutex_unlock();
}

// void	print_log(char *msg)
// {
// 	pthread_mutex_lock(&msg);

// 	pthread_mutex_unlock(&msg);
// }

void *do_something(void *args)
{
	grab_forks();
	return (NULL);
}
