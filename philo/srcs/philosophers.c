/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 15:35:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static int	print_error(int err_code)
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

static int	is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (ft_is_sign(str[i]))
		i++;
	if (!ft_is_digit(str[i]))
		return (0);
	while (ft_is_digit(str[i]))
		i++;
	while (ft_is_space(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

static int	has_non_numeric_param(char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	has_negative_number(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (*args[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	out_of_range(char **args)
{
	int			i;
	long int	number;

	i = 1;
	while (args[i])
	{
		number = ft_atol(args[i]);
		if (number < 0 || number > PH_MAX_INT)
			return (1);
		i++;
	}
	return (0);
}

static int	valid_philos(char *philos_nptr)
{
	long int	number;

	number = ft_atol(philos_nptr);
	if (number <= 0 || number > PH_MAX_INT)
		return (0);
	return (1);
}

static int	valid_args(int params, char **args)
{
	if (params != 4 && params != 5)
		return (print_error(1));
	else if (has_non_numeric_param(args))
		return (print_error(2));
	else if (has_negative_number(args))
		return (print_error(3));
	else if (out_of_range(args))
		return (print_error(4));
	else if (!valid_philos(args[1]))
		return (print_error(5));
	return (1);
}

int main(int argc, char **argv)
{
	if (!valid_args(argc - 1, argv))
		return (1);
	return (0);
}
