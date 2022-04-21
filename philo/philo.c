/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:19:50 by hloke             #+#    #+#             */
/*   Updated: 2022/04/21 16:41:34 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t fun;
int counter;

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

void	grab_fork(t_info *info, int philo_id)
{
	pthread_mutex_lock(&info->fork[philo_id]);
	
	pthread_mutex_unlock(&info->fork[philo_id]);
}

static void	*activity(t_philo *self)
{
	return (NULL);
}

// void	thread_handler(int num_of_philos, t_philo *philo)
// {
// 	int			i;
// 	pthread_t	tid[num_of_philos];

// 	i = 0;
// 	while (i < num_of_philos)
// 	{
// 		pthread_create(&tid[i], NULL, &activity, &philo[i]);
// 		i += 1;
// 	}
// 	i = 0;
// 	while (i < num_of_philos)
// 		pthread_join(tid[i++], NULL);
// }
