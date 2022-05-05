/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:11:47 by hloke             #+#    #+#             */
/*   Updated: 2022/05/05 14:46:59 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_eats(t_rules *r, t_philo *self)
{
	sem_wait(r->forks);
	print_action(r, self->id, GRAB_FORK);
	sem_wait(r->forks);
	print_action(r, self->id, GRAB_FORK);
	self->time_last_eat = timestamp_ms();
	self->timer = r->time_die;
	print_action(r, self->id, EATING);
	if (self->timer < r->time_eat)
	{
		smart_sleep(self->timer);
		exit (EXIT_FAILURE);
	}
	smart_sleep(r->time_eat);
	self->timer -= r->time_eat;
	self->eat_count += 1;
	sem_post(r->forks);
	sem_post(r->forks);
	return (0);
}

int	philo_sleeps(t_rules *r, t_philo *self)
{
	int	i;

	if (self->timer <= 0)
		exit (EXIT_FAILURE);
	print_action(r, self->id, SLEEPING);
	if (self->timer < r->time_sleep)
	{
		smart_sleep(self->timer);
		exit (EXIT_FAILURE);
	}
	smart_sleep(r->time_sleep);
	self->timer -= r->time_sleep;
	i = 0;
	while (i < (r->time_sleep / r->time_eat))
	{
		queue_increment(r->nb_philos, self->queue_map);
		i += 1;
	}
	return (0);
}

int	philo_thinks(t_rules *r, t_philo *self)
{
	print_action(r, self->id, THINKING);
	if (self->timer < (r->time_eat - r->time_sleep))
	{
		smart_sleep(self->timer);
		exit (EXIT_FAILURE);
	}
	while (queue_turn(r, self) != true)
	{
		if (self->timer < r->time_eat)
		{
			smart_sleep(self->timer);
			exit (EXIT_FAILURE);
		}
		smart_sleep(r->time_eat);
		self->timer -= r->time_eat;
		queue_increment(r->nb_philos, self->queue_map);
	}
	queue_increment(r->nb_philos, self->queue_map);
	return (0);
}
