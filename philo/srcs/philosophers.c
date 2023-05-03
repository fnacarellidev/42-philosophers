/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 19:46:28 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	init_philos(t_table *table)
{
	int		i;
	int		left_idx;
	int		philos_qty;
	t_philo	*curr_philo;

	i = 0;
	philos_qty = table->nbr_of_philos;
	table->philo = malloc(sizeof(t_philo) * philos_qty);
	while (i < philos_qty)
	{
		curr_philo = (table->philo) + i;
		curr_philo->id = i;
		left_idx = (i + philos_qty - 1) % philos_qty;
		curr_philo->fork_left = &(table->philo[left_idx].fork);
		pthread_mutex_init(&curr_philo->fork, NULL);
		i++;
	}
}

static void	init_table(t_table *table, char **argv)
{
	table->nbr_of_philos = ft_atol(argv[1]);
	init_philos(table);
}

static void	die(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_destroy(&table->philo[i].fork);
		i++;
	}
	free(table->philo);
}

int	main(int argc, char **argv)
{
	t_table		table;

	if (!valid_args(argc - 1, argv))
		return (1);
	init_table(&table, argv);
	die(&table);
	return (0);
}
