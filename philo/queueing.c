/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queueing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:08:58 by hloke             #+#    #+#             */
/*   Updated: 2022/04/28 23:08:22 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* increase the count of each number in the queueing map to let next philo
//* take their turn
//* if count == number of philos, then set it back to zero
void	queue_increment(int nb_philos, int queue_map[100])
{
	int	i;

	i = 0;
	while (i < (nb_philos / 2))
	{
		queue_map[i] += 1;
		if (queue_map[i] == nb_philos)
			queue_map[i] = 0;
		i += 1;
	}
}

//* initialize a queueing map for every philosopher
//* always start from 0, then increment by 2
void	queue_map_init(int nb_philos, t_philo *philo)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < (nb_philos / 2))
	{
		philo->queue_map[i] = num;
		num += 2;
		i += 1;
	}
}

//* check if it is their current turn to eat
//* returns true if its their turn, else false
bool	queue_turn(t_rules *r, t_philo *self)
{
	int	i;

	i = 0;
	while (i < (r->nb_philos / 2))
	{
		if (self->id == self->queue_map[i])
			return (true);
		i += 1;
	}
	return (false);
}
