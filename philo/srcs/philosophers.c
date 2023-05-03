/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 14:26:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	print_error(int err_code)
{
	if (err_code == 1)
	{
		write(2, "Usage: number_of_philos time_to_die time_to_eat " \
			"time_to_sleep [number_of_times_each_philo_eats]\n", 96);
	}
	else if (err_code == 2)
	{
		write(2, "Error: Non numeric parameter detected, pass only int params" \
			" to the program\n", 75);
	}
	else if (err_code == 3)
	{
		write(2, "Error: Can't receive negative numbers as parameters, only " \
			"positive integers, please\n", 84);
	}
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

static int	valid_args(int params, char **args)
{
	if (params != 4 && params != 5)
	{
		print_error(1);
		return (0);
	}
	else if (has_non_numeric_param(args))
	{
		print_error(2);
		return (0);
	}
	else if (has_negative_number(args))
	{
		print_error(3);
		return (0);
	}
	else if (out_of_range(args))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	if (!valid_args(argc - 1, argv))
		return (1);
	return (0);
}
