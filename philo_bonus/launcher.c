/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:19:48 by hloke             #+#    #+#             */
/*   Updated: 2022/05/04 17:10:08 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	exit_handler(t_rules *r)
{
	if (sem_close(r->message) != 0)
		return (4);
	sem_unlink("/sem_message");
	if (sem_close(r->forks) != 0)
		return (4);
	sem_unlink("/sem_forks");
	return (0);
}

static int	child_process(t_rules *r, t_philo *self)
{
	self->time_last_eat = timestamp_ms();
	self->timer = r->time_die;
	self->process_id = fork();
	if (self->process_id == -1)
		return (3);
	if (self->process_id == 0)
	{
		while (self->eat_count < r->nb_eat)
		{		
			philo_thinks(r, self);
			philo_eats(r, self);
			philo_sleeps(r, self);
		}
		exit (EXIT_SUCCESS);
	}
	return (0);
}

static void	death_check(t_rules *r)
{
	int	i;
	int	pid;
	int	status;

	pid = waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			printf(RED "%li %i died\n", timestamp_ms(),
				pid - r->philo[0].process_id + 1);
			i = 0;
			while (i < r->nb_philos)
			{
				kill (r->philo[i].process_id, SIGKILL);
				i += 1;
			}
		}
	}
	while (waitpid(-1, &status, 0) > 0)
		;
}

int	launcher(t_rules *r)
{
	int		i;

	i = 0;
	while (i < r->nb_philos)
	{
		if (child_process(r, &r->philo[i]) != 0)
			return (3);
		i += 1;
	}
	death_check(r);
	return (exit_handler(r));
}
