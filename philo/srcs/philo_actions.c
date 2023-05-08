/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:01:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/08 17:45:52 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

void	think(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d is thinking\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
	usleep(500);
}

void	rest(t_philo *philo)
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

void	eat(t_philo *philo)
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

void	take_forks(t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->fork);
	else
		pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d has taken a fork\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->fork_left);
	else
		pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	printf("%ld %d has taken a fork\n", curr_ms - philo->ms_init_timestamp, philo->id);
	pthread_mutex_unlock(philo->g_mut);
}
