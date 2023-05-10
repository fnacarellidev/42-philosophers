/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:09:09 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/10 20:09:15 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers_bonus.h"

int	print_error(int err_code)
{
	if (err_code == EPARAM)
	{
		write(2, "Usage: number_of_philos time_to_die time_to_eat " \
			"time_to_sleep [number_of_times_each_philo_eats]\n", 96);
	}
	else if (err_code == ENOTNUMPARAM)
	{
		write(2, "Error: Non numeric parameter detected, pass only int params" \
			" to the program\n", 75);
	}
	else if (err_code == ELESSZERO)
	{
		write(2, "Error: Can't receive negative numbers as parameters, only " \
			"positive integers, please\n", 84);
	}
	else if (err_code == EINTRANGE)
		write(2, "Error: Numbers above (2^31) - 1 are not valid \n", 47);
	else if (err_code == EPHILO)
	{
		write(2, "Error: Number of philos must be greater than 0 and " \
				"less than (2^31) - 1\n", 73);
	}
	return (0);
}
