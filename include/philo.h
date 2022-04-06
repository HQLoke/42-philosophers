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

//* Colors used in printf for visualizing
# define BOLD    "\x1b[1m"
# define ITALIC  "\x1b[3m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct s_philo
{
	int id;
	int	left_fork_id;
	int	right_fork_id;
	int is_dead;
}	t_philo;

typedef	struct s_state
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	pthread_t *philo;
	pthread_mutex_t message;
}	t_state;

//*	---------- philo_init.c ----------


//*	---------- ft_utils.c ----------
int		ft_atoi(const char *str);

#endif