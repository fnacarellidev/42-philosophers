/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 16:51:39 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	die(t_philo *philo, int philos_qty)
{
	int	i;

	i = 0;
	while (i < philos_qty)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	free(philo);
}

int	main(int argc, char **argv)
{
	int		philos_qty;
	t_philo	*philo;

	if (!valid_args(argc - 1, argv))
		return (1);
	philos_qty = ft_atol(argv[1]);
	init_philos(&philo, philos_qty, argv);
	solve_n_philos(philo, philos_qty);
	die(philo, philos_qty);
	return (0);
}
