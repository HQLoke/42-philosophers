/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:19 by hloke             #+#    #+#             */
/*   Updated: 2022/04/20 19:27:47 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* teach the evaluator what inputs to enter to use the program
void	teach_them(void)
{
	printf("Usage: ./philo [number_of_philosophers] [time_to_die] ");
	printf("[time_to_eat] [time_to_sleep]\n");
	printf("\t(optional)[number_of_times_each_philosopher_must eat]\n");
}

//* initialize the info struct, which keeps all the common information
//* initialize all philo structs, which keep personal philo information
//* returns the pointer to an array of philo pointers
t_philo	*philo_init(char **argv, t_info **info)
{
	int		i;
	t_philo	*philos;

	*info = ft_calloc(1, sizeof(t_info));
	(*info)->num_of_philos = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	(*info)->must_eat_count = INT32_MAX;
	if (argv[5] != NULL)
		(*info)->must_eat_count = ft_atoi(argv[5]);
	(*info)->all_alive = true;
	(*info)->fork = ft_calloc(ft_atoi(argv[1]), sizeof(pthread_mutex_t));
	philos = ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].philo_id = i;
		philos[i].fork_left = 0;
		philos[i].fork_right = 0;
		philos[i].times_eaten = 0;
		philos[i].info = *info;
		i += 1;
	}
	return (philos);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
	{
		teach_them();
		return (1);
	}
	philos = philo_init(argv, &info);
	
	return (0);
}
