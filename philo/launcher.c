/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:19:48 by hloke             #+#    #+#             */
/*   Updated: 2022/04/27 17:54:56 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*activity(void *philosopher)
{
	t_philo	*self;
	t_rules	*r;

	self = (t_philo *)philosopher;
	r = self->rules;
	while (self->eat_count < r->nb_eat)
	{
		
		self->eat_count += 1;
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
	if (pthread_mutex_destroy(&r->death) != 0)
		return (5);
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
