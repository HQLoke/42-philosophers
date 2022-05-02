/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:11:47 by hloke             #+#    #+#             */
/*   Updated: 2022/05/02 16:05:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_grabs_forks(t_rules *r, t_philo *self)
{
	if (self->id % 2 == 0)
	{
		pthread_mutex_lock(&r->fork[self->left_fork_id]);
		print_action(r, self->id, GRAB_FORK);
		pthread_mutex_lock(&r->fork[self->right_fork_id]);
		print_action(r, self->id, GRAB_FORK);
	}
	else
	{
		pthread_mutex_lock(&r->fork[self->right_fork_id]);
		print_action(r, self->id, GRAB_FORK);
		pthread_mutex_lock(&r->fork[self->left_fork_id]);
		print_action(r, self->id, GRAB_FORK);
	}
}

int	philo_eats(t_rules *r, t_philo *self)
{
	philo_grabs_forks(r, self);
	self->time_last_eat = timestamp_ms();
	self->timer = r->time_die;
	print_action(r, self->id, EATING);
	if (self->timer < r->time_eat)
	{
		smart_sleep(self->timer);
		print_action(r, self->id, DIED);
		return (1);
	}
	smart_sleep(r->time_eat);
	self->timer -= r->time_eat;
	self->eat_count += 1;
	pthread_mutex_unlock(&r->fork[self->left_fork_id]);
	pthread_mutex_unlock(&r->fork[self->right_fork_id]);
	return (0);
}

int	philo_sleeps(t_rules *r, t_philo *self)
{
	if (self->timer <= 0)
	{
		print_action(r, self->id, DIED);
		return (1);
	}
	print_action(r, self->id, SLEEPING);
	if (self->timer < r->time_sleep)
	{
		smart_sleep(self->timer);
		print_action(r, self->id, DIED);
		return (1);
	}
	smart_sleep(r->time_sleep);
	self->timer -= r->time_sleep;
	queue_increment(r->nb_philos, self->queue_map);
	return (0);
}

int	philo_thinks(t_rules *r, t_philo *self)
{
	print_action(r, self->id, THINKING);
	if (self->timer < (r->time_eat - r->time_sleep))
	{
		smart_sleep(self->timer);
		print_action(r, self->id, DIED);
		return (1);
	}
	while (queue_turn(r, self) != true)
	{
		if (self->timer < r->time_eat)
		{
			smart_sleep(self->timer);
			print_action(r, self->id, DIED);
			return (1);
		}
		smart_sleep(r->time_eat);
		self->timer -= r->time_eat;
		queue_increment(r->nb_philos, self->queue_map);
	}
	queue_increment(r->nb_philos, self->queue_map);
	return (0);
}
