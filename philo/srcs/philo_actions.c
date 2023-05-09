/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:01:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 14:37:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

void	mut_print(char *suffix, t_philo *philo)
{
	int		id;
	time_t	init_timestamp;

	id = philo->id;
	init_timestamp = philo->ms_init_timestamp;
	pthread_mutex_lock(philo->g_mut);
	if (ft_strcmp("thinking", suffix) == 0)
		printf("%ld %d is thinking\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("sleeping", suffix) == 0)
		printf("%ld %d is sleeping\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("eating", suffix) == 0)
		printf("%ld %d is eating\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("fork", suffix) == 0)
		printf("%ld %d has taken a fork\n", \
				get_ms_timestamp() - init_timestamp, id);
	pthread_mutex_unlock(philo->g_mut);
}

void	think(t_philo *philo)
{
	mut_print("thinking", philo);
	usleep(500);
}

void	rest(t_philo *philo)
{
	mut_print("sleeping", philo);
	usleep(milli_to_micro(philo->info.time_to_sleep));
}

void	eat(t_philo *philo)
{
	mut_print("eating", philo);
	usleep(milli_to_micro(philo->info.time_to_eat));
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_lock(philo->g_mut);
	philo->last_meal = get_ms_timestamp();
	pthread_mutex_unlock(philo->g_mut);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->fork);
	else
		pthread_mutex_lock(philo->fork_left);
	mut_print("fork", philo);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->fork_left);
	else
		pthread_mutex_lock(&philo->fork);
	mut_print("fork", philo);
}
