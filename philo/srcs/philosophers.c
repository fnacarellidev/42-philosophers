/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 16:25:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static int	has_non_numeric_param(char **args)
{
	int	i;

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
		return (print_error(EPARAM));
	else if (has_non_numeric_param(args))
		return (print_error(ENOTNUMPARAM));
	else if (has_negative_number(args))
		return (print_error(ELESSZERO));
	else if (out_of_range(args))
		return (print_error(EINTRANGE));
	else if (!valid_philos(args[1]))
		return (print_error(EPHILO));
	return (1);
}

int	main(int argc, char **argv)
{
	if (!valid_args(argc - 1, argv))
		return (1);
	return (0);
}
