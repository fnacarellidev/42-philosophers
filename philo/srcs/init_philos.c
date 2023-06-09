/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:08 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 13:26:30 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static int	count_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void	init_philos_info(t_philo *philo, int philos_qty, char **argv)
{
	int		i;
	int		args;
	t_info	info;

	i = 0;
	args = count_argv(argv);
	info.time_to_die = ft_atol(argv[2]);
	info.time_to_eat = ft_atol(argv[3]);
	info.time_to_sleep = ft_atol(argv[4]);
	if (args == 6)
		info.eat_many_times = ft_atol(argv[5]);
	else
		info.eat_many_times = -1;
	while (i < philos_qty)
	{
		philo[i].stop_simulation = 0;
		philo[i].info.time_to_die = info.time_to_die;
		philo[i].info.time_to_eat = info.time_to_eat;
		philo[i].info.time_to_sleep = info.time_to_sleep;
		philo[i].info.eat_many_times = info.eat_many_times;
		i++;
	}
}

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
		curr_philo->g_mut = philo[0].g_mut;
		left_idx = (i + philos_qty - 1) % philos_qty;
		curr_philo->fork_left = &philo[left_idx].fork;
		i++;
	}
}

void	init_philos(t_philo **ptr_address, int philos_qty, char **argv)
{
	int		i;
	t_philo	*philo;
	time_t	ms_timestamp;

	i = 0;
	philo = malloc(sizeof(t_philo) * philos_qty);
	init_philos_ids(philo, philos_qty);
	init_philos_mutexes(philo, philos_qty);
	init_philos_info(philo, philos_qty, argv);
	ms_timestamp = get_ms_timestamp();
	while (i < philos_qty)
	{
		philo[i].ms_init_timestamp = ms_timestamp;
		philo[i].last_meal = ms_timestamp;
		i++;
	}
	*ptr_address = philo;
}
