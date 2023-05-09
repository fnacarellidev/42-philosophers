/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:01:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 15:21:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

void	mut_print(char *suffix, t_philo *philo)
{
	int		id;
	int		stop_simulation;
	time_t	init_timestamp;

	id = philo->id;
	init_timestamp = philo->ms_init_timestamp;
	stop_simulation = philo->stop_simulation;
	pthread_mutex_lock(philo->g_mut);
	if (ft_strcmp("thinking", suffix) == 0 && !stop_simulation)
		printf("%ld %d is thinking\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("sleeping", suffix) == 0 && !stop_simulation)
		printf("%ld %d is sleeping\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("eating", suffix) == 0 && !stop_simulation)
		printf("%ld %d is eating\n", get_ms_timestamp() - init_timestamp, id);
	else if (ft_strcmp("fork", suffix) == 0 && !stop_simulation)
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
	if (!philo->stop_simulation)
	{
		mut_print("eating", philo);
		usleep(milli_to_micro(philo->info.time_to_eat));
		philo->info.eat_many_times--;
	}
	philo->last_meal = get_ms_timestamp();
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->fork_left);
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
