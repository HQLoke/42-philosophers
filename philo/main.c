/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:19 by hloke             #+#    #+#             */
/*   Updated: 2022/05/03 10:48:59 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* teach the evaluator what inputs to enter to use the program
static int	teach_them(void)
{
	printf("Usage: ./philo [number_of_philosophers] [time_to_die] ");
	printf("[time_to_eat] [time_to_sleep]\n");
	printf("\t(optional)[number_of_times_each_philosopher_must eat]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (teach_them());
	ret = init_all(argv, &rules);
	if (ret != 0)
		return (error_handler(ret));
	launcher(&rules);
	return (0);
}
