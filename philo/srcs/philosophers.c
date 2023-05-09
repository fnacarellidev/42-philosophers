/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:23 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

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

static void	solve_n_philos(t_philo *philo, int philos_qty)
{
	int				i;
	t_philo			*curr_philo;
	t_philo_info	philo_info;

	i = 0;
	philo_info.philo = philo;
	philo_info.philo_qty = philos_qty;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		pthread_create(&curr_philo->thread, NULL, &simulation, (void *)curr_philo);
		i++;
	}
	philo_info.g_mut = philo[0].g_mut;
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
