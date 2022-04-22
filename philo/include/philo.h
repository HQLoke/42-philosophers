/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:15 by hloke             #+#    #+#             */
/*   Updated: 2022/04/22 16:52:34 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

enum e_action
{
	TAKE_FORK,
	EATING,
	THINKING,
	SLEEPING,
	DIED
};

//* list of all variables specific to each philosopher
typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				nb_has_eaten;
	pthread_t		thread_id;
	struct s_rules	*rules;
}	t_philo;

//* list of all common variables shared by all philosophers
//* nb = number
typedef struct s_rules
{
	int				nb_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	bool			all_alive;
	pthread_mutex_t	message;
	pthread_mutex_t	fork[1000];
	t_philo			philo[1000];
}	t_rules;

//* init.c
int		init_all(char **argv, t_rules *r);

//* ft_utils.c
int		ft_atoi(const char *str);

#endif