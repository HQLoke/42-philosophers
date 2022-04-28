/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:11:47 by hloke             #+#    #+#             */
/*   Updated: 2022/04/28 18:20:23 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eats(t_rules *r, t_philo *self)
{
	pthread_mutex_lock(&r->fork[self->left_fork_id]);
	//print_action(r, self->id, GRAB_FORK);
	pthread_mutex_lock(&r->fork[self->right_fork_id]);
	//print_action(r, self->id, GRAB_FORK);
	self->timer = r->time_die;
	//print_action(r, self->id, EATING);
	if (self->timer - r->time_eat < 0)
	{
		smart_sleep(self->timer);
		//print_action(r, self->id, DIED);
		return (1);
	}
	else
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
		//print_action(r, self->id, DIED);
		return (1);
	}
	//print_action(r, self->id, SLEEPING);
	if (self->timer < r->time_sleep)
	{
		smart_sleep(self->timer);
		//print_action(r, self->id, DIED);
		return (1);
	}
	smart_sleep(r->time_sleep);
	self->timer -= r->time_sleep;
	return (0);
}

int	philo_thinks(t_rules *r, t_philo *self)
{
	//print_action(r, self->id, THINKING);
	while (queue_turn(r, self) == false)
	{
		if (self->timer - r->time_eat > 0)
		{
			queue_increment(r->nb_philos, self->queue_map);
			smart_sleep(r->time_eat);
			self->timer -= r->time_eat;
		}
		else
		{
			smart_sleep(self->timer);
			//print_action(r, self->id, DIED);
			return (1);
		}
	}
	queue_increment(r->nb_philos, self->queue_map);
	return (0);
}
