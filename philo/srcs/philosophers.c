/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/04 18:35:04 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(philo->g_mut);
	printf("Hello from thread %d\n", philo->id);
	pthread_mutex_unlock(philo->g_mut);
	return (NULL);
}

static void	init_threads(t_philo *philo, int philos_qty)
{
	int		i;
	t_philo	*curr_philo;

	i = 0;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		pthread_create(&curr_philo->thread, NULL, &routine, (void *)curr_philo);
		i++;
	}
	i = 0;
	while (i < philos_qty)
	{
		curr_philo = philo + i;
		pthread_join(curr_philo->thread, NULL);
		i++;
	}
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
	init_philos(&philo, philos_qty);
	init_threads(philo, philos_qty);
	die(philo, philos_qty);
	return (0);
}
