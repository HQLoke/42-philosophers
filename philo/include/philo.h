/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:15 by hloke             #+#    #+#             */
/*   Updated: 2022/04/27 17:34:37 by hloke            ###   ########.fr       */
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

# define RED	"\e[0;31m"
# define GRN	"\e[0;32m"
# define YEL	"\e[0;33m"
# define BLU	"\e[0;34m"
# define MAG	"\e[0;35m"
# define CYN	"\e[0;36m"
# define RESET	"\e[0m"

enum e_action
{
	GRAB_FORK,
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
	int				eat_count;
	long			time_last_eat;
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
	pthread_mutex_t	death;
	pthread_mutex_t	message;
	pthread_mutex_t	fork[200];
	t_philo			philo[200];
}	t_rules;

//* error_handler.c
int		error_handler(int error_code);
int		write_error(char *str);

//* init.c
int		init_all(char **argv, t_rules *r);

//* launcher.c
int		launcher(t_rules *r);

//* utils.c
int		ft_atoi(const char *str);
void	print_action(t_rules *r, int philo_id, int action);
void	smart_sleep(int time_in_ms);
long	timestamp_ms(void);

#endif