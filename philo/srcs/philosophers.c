/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/04 16:11:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	init_philos_ids(t_philo *philo, int philos_qty)
{
	int	i;

	i = 0;
	while (i < philos_qty)
	{
		philo[i].id = i + 1;
		i++;
	}
}

static void	init_philos(t_philo **philo_address, int philos_qty)
{
	*philo_address = malloc(sizeof(t_philo) * philos_qty);
	init_philos_ids(*philo_address, philos_qty);
}

static void	die(t_philo *philo)
{
	free(philo);
}

int	main(int argc, char **argv)
{
	int		philos_qty;
	t_philo	*philo;

	if (!valid_args(argc - 1, argv))
		return (1);
	philos_qty = ft_atol(argv[1]);
	init_philos(&philo, philos_qty);
	die(philo);
	return (0);
}
