/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:02:55 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/17 12:33:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

void	kill_philo(t_data *data, t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;
	time_t			death_timestamp;

	gettimeofday(&tv, NULL);
	curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	death_timestamp = philo->timers.last_meal + philo->timers.time_to_die;
	usleep((death_timestamp - curr_ms) * 1000);
	sem_wait(data->print_sem);
	gettimeofday(&tv, NULL);
	curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%ld\t%ld died\n", curr_ms - data->ms_init, philo->id);
	sem_close(data->forks);
	sem_close(data->print_sem);
	die(data);
	exit(1);
}

void	take_forks(t_data *data, t_philo *philo)
{
	sem_wait(data->forks);
	sem_wait(data->forks);
	print_action("fork", data->ms_init, *philo);
	print_action("fork", data->ms_init, *philo);
}

void	eat(t_data *data, t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;
	time_t			death_timestamp;
	time_t			action_timestamp;

	gettimeofday(&tv, NULL);
	curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	death_timestamp = philo->timers.last_meal + philo->timers.time_to_die;
	action_timestamp = curr_ms + philo->timers.time_to_eat;
	print_action("eating", data->ms_init, *philo);
	if (action_timestamp > death_timestamp)
		kill_philo(data, philo);
	usleep(philo->timers.time_to_eat * 1000);
	gettimeofday(&tv, NULL);
	curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	philo->timers.last_meal = curr_ms;
	philo->meals--;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	rest(t_data *data, t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;
	time_t			death_timestamp;
	time_t			action_timestamp;

	gettimeofday(&tv, NULL);
	curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	death_timestamp = philo->timers.last_meal + philo->timers.time_to_die;
	action_timestamp = curr_ms + philo->timers.time_to_eat;
	print_action("sleeping", data->ms_init, *philo);
	if (action_timestamp > death_timestamp)
		kill_philo(data, philo);
	usleep(philo->timers.time_to_sleep * 1000);
}

void	think(t_data *data, t_philo *philo)
{
	print_action("thinking", data->ms_init, *philo);
	usleep(500);
}
