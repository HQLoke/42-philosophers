/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:15 by hloke             #+#    #+#             */
/*   Updated: 2022/04/23 10:10:34 by hloke            ###   ########.fr       */
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
	long long		time_last_eat;
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

//* actions.c
void	print_log(t_rules *r, int philo_id, int action);

//* error_handler.c
int		error_handler(int error_code);
int		write_error(char *str);

//* init.c
int		init_all(char **argv, t_rules *r);

//* launcher.c
int		launcher(t_rules *r);

//* utils.c
int		ft_atoi(const char *str);
long	get_time_in_ms(void);

#endif