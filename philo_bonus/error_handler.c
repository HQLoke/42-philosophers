/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:49:00 by hloke             #+#    #+#             */
/*   Updated: 2022/05/04 15:11:19 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_handler(int error_code)
{
	if (error_code == 1)
		return (write_error("at least 1 argument is invalid"));
	else if (error_code == 2)
		return (write_error("sem open failed"));
	else if (error_code == 3)
		return (write_error("fork failed"));
	else if (error_code == 4)
		return (write_error("sem close failed"));
	else
		return (write_error("undefined error has occured"));
}

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, str, len);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}
