/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:59:44 by hloke             #+#    #+#             */
/*   Updated: 2022/04/21 15:03:59 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_info *info, int philo_id, int action)
{
	pthread_mutex_lock(&info->log);
	if (action == TAKE_FORK)
		printf("%li %3i has taken a fork.\n", get_time_in_ms(), philo_id);
	else if (action == EATING)
		printf("%li %3i is eating.\n", get_time_in_ms(), philo_id);
	else if (action == THINKING)
		printf("%li %3i is thinking.\n", get_time_in_ms(), philo_id);
	else if (action == SLEEPING)
		printf("%li %3i is sleeping.\n", get_time_in_ms(), philo_id);
	else if (action == DIED)
		printf("%li %3i has died.\n", get_time_in_ms(), philo_id);
	pthread_mutex_unlock(&info->log);
}
