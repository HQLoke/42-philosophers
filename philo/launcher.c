/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:19:48 by hloke             #+#    #+#             */
/*   Updated: 2022/04/24 22:25:44 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	death_check(t_rules *r)
{
	
}

static int	exit_handler(t_rules *r)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = r->philo;
	while (i < r->nb_philos)
		if (pthread_join(philo[i++].thread_id, NULL) != 0)
			return (4);
	i = 0;
	while (i < r->nb_philos)
		if (pthread_mutex_destroy(&r->fork[i++]) != 0)
			return (5);
	if (pthread_mutex_destroy(&r->message) != 0)
		return (5);
	return (0);
}

static void	*activity(void *philosopher)
{
	t_philo *philo;
	t_rules	*rules;

	philo = (t_philo *)philosopher;
	rules = philo->rules;
	while (rules->all_eaten != true)
	{
		if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(&rules->fork[philo->left_fork_id]);
			printf("%li %i has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_lock(&rules->fork[philo->right_fork_id]);
			printf("%li %i has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&rules->fork[philo->left_fork_id]);
			pthread_mutex_unlock(&rules->fork[philo->right_fork_id]);
		}
		else
		{
			pthread_mutex_lock(&rules->fork[philo->right_fork_id]);
			printf("%li %i has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_lock(&rules->fork[philo->left_fork_id]);
			printf("%li %i has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&rules->fork[philo->right_fork_id]);
			pthread_mutex_unlock(&rules->fork[philo->left_fork_id]);
		}
		
	}
	return (NULL);
}

int	launcher(t_rules *r)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = r->philo;
	while (i < r->nb_philos)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &activity,
			(void *)&philo[i]) != 0)
			return (3);
		i += 1;
	}
	
	return (exit_handler(r));
}
