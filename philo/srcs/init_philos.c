/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:08 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/04 16:50:50 by fnacarel         ###   ########.fr       */
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

static void	init_philos_mutexes(t_philo *philo, int philos_qty)
{
	int		i;
	int		left_idx;
	t_philo	*curr_philo;

	i = 0;
	philo[0].g_mut = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[0].g_mut, NULL);
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		curr_philo->g_mut = philo[0].g_mut;
		pthread_mutex_init(&curr_philo->fork, NULL);
		i++;
	}
	i = 0;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		left_idx = (i + philos_qty - 1) % philos_qty;
		curr_philo->fork_left = &philo[left_idx].fork;
		i++;
	}
}

void	init_philos(t_philo **philo_address, int philos_qty)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * philos_qty);
	init_philos_ids(philo, philos_qty);
	init_philos_mutexes(philo, philos_qty);
	*philo_address = philo;
}

