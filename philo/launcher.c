/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:19:48 by hloke             #+#    #+#             */
/*   Updated: 2022/05/02 10:44:42 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_rules *r)
{
	int	temp;

	pthread_mutex_lock(&r->message);
	temp = r->death;
	pthread_mutex_unlock(&r->message);
	return (temp);
}

static void	*activity(void *philosopher)
{
	t_philo	*self;
	t_rules	*r;

	self = (t_philo *)philosopher;
	r = self->rules;
	self->time_last_eat = timestamp_ms();
	self->timer = r->time_die;
	while ((self->eat_count < r->nb_eat) && check_death(r) == 0)
	{		
		if (philo_thinks(r, self) != 0)
			return ((void *) 42);
		if (philo_eats(r, self) != 0)
			return ((void *) 42);
		if (philo_sleeps(r, self) != 0)
			return ((void *) 42);
	}
	return (NULL);
}

static int	exit_handler(t_rules *r)
{
	int		i;

	i = 0;
	while (i < r->nb_philos)
		if (pthread_join(r->philo[i++].thread_id, NULL) != 0)
			return (4);
	if (pthread_mutex_destroy(&r->message) != 0)
		return (5);
	i = 0;
	while (i < r->nb_philos)
		if (pthread_mutex_destroy(&r->fork[i++]) != 0)
			return (5);
	return (0);
}

int	launcher(t_rules *r)
{
	int		i;

	i = 0;
	while (i < r->nb_philos)
	{
		if (pthread_create(&r->philo[i].thread_id, NULL, &activity,
				(void *)&r->philo[i]) != 0)
			return (3);
		i += 1;
	}
	return (exit_handler(r));
}
