/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:50:42 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 17:37:42 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	*single_philo(void *ptr)
{
	time_t	curr_ms;
	time_t	init_ms;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	init_ms = philo->ms_init_timestamp;
	curr_ms = get_ms_timestamp();
	pthread_mutex_lock(&philo->fork);
	printf("%ld\t1 has taken a fork\n", curr_ms - init_ms);
	usleep(milli_to_micro(philo->info.time_to_die));
	curr_ms = get_ms_timestamp();
	printf("%ld\t1 died\n", curr_ms - init_ms);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	solve_single_philo(t_philo *philo)
{
	pthread_create(&philo[0].thread, NULL, &single_philo, (void *)&philo[0]);
	pthread_join(philo[0].thread, NULL);
}

static void	*simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		if (!philo->stop_simulation)
		{
			rest(philo);
			think(philo);
		}
		if (philo->info.eat_many_times == 0 || philo->stop_simulation)
			return (NULL) ;
	}
	return (NULL);
}

static void	init_info(t_philo_info *philo_info, t_philo *philo, int philos_qty)
{
	philo_info->philo = philo;
	philo_info->philo_qty = philos_qty;
	philo_info->g_mut = philo[0].g_mut;
}

void	solve_n_philos(t_philo *philo, int philos_qty)
{
	int				i;
	t_philo			*curr_philo;
	t_philo_info	philo_info;

	i = 0;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		pthread_create(&curr_philo->thread, NULL, &simulation, (void *)curr_philo);
		i++;
	}
	init_info(&philo_info, philo, philos_qty);
	pthread_create(&philo_info.thread, NULL, &philos_watcher, (void *)&philo_info);
	i = 0;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		pthread_join(curr_philo->thread, NULL);
		i++;
	}
	pthread_join(philo_info.thread, NULL);
}
