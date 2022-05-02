/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:13:32 by hloke             #+#    #+#             */
/*   Updated: 2022/05/02 20:44:29 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_mutex(t_rules *r)
{
	int	num;

	num = r->nb_philos;
	if (pthread_mutex_init(&r->message, NULL) != 0)
		return (2);
	while (--num >= 0)
	{
		if (pthread_mutex_init(&r->fork[num], NULL) != 0)
			return (2);
	}
	return (0);
}

static void	init_philos(t_rules *r)
{
	int	num;

	num = r->nb_philos;
	while (--num >= 0)
	{
		r->philo[num].id = num;
		r->philo[num].left_fork_id = num;
		r->philo[num].right_fork_id = (num + 1) % r->nb_philos;
		r->philo[num].eat_count = 0;
		r->philo[num].rules = r;
		queue_map_init(r->nb_philos, &r->philo[num]);
	}
}

int	init_all(char **argv, t_rules *r)
{
	r->nb_philos = ft_atoi(argv[1]);
	r->time_die = ft_atoi(argv[2]);
	r->time_eat = ft_atoi(argv[3]);
	r->time_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		r->nb_eat = ft_atoi(argv[5]);
	else
		r->nb_eat = 2147483647;
	if (r->nb_philos < 1 || r->nb_philos > 200 || r->time_die < 60
		|| r->time_eat < 60 || r->time_sleep < 60 || r->nb_eat < 0)
		return (1);
	r->death = 0;
	init_philos(r);
	return (init_mutex(r));
}
