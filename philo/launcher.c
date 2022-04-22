/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:19:48 by hloke             #+#    #+#             */
/*   Updated: 2022/04/22 17:09:13 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*activity()
{
	
}

int	launcher(t_rules *r)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = r->philo;
	while (i < r->nb_philos)
	{
		if (pthread_create(&philo[i].thread_id, NULL, ) != 0)
			return (1);
		i += 1;
	}
}
