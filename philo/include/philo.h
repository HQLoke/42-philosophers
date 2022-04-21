/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:15 by hloke             #+#    #+#             */
/*   Updated: 2022/04/21 15:12:11 by hloke            ###   ########.fr       */
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

//* list of all common variables shared by all philosophers
typedef struct s_info
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	bool			all_alive;
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
}	t_info;

//* list of all variables specific to each philosopher
typedef struct s_philo
{
	int				philo_id;
	int				fork_left;
	int				fork_right;
	int				times_eaten;
	struct s_info	*info;
}	t_philo;

//* actions.c

//* philo.c
void	thread_handler(int num_of_philos, t_philo *philo);

//* ft_utils.c
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif