#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

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

//* ft_utils.c
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif