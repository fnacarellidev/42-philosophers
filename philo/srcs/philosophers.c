/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/08 15:17:55 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	think(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d is thinking\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
}

static void	rest(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d is sleeping\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
	usleep(milli_to_micro(philo->info.time_to_sleep));
}

static void	eat(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d is eating\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
	usleep(milli_to_micro(philo->info.time_to_eat));
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->fork_left);
}

static void	take_forks(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d has taken a fork\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d has taken a fork\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
}

static void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		rest(philo);
		think(philo);
	}
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
	init_philos(&philo, philos_qty, argv);
	init_threads(philo, philos_qty);
	die(philo, philos_qty);
	return (0);
}
