/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:02:55 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/16 13:38:09 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

void	print_action(char *suffix, time_t init_ms, t_philo philo)
{
	struct timeval	tv;
	time_t			curr_ms;
	time_t			time_elapsed;

	gettimeofday(&tv, NULL);
	curr_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time_elapsed = curr_ms - init_ms;
	if (ft_strcmp("thinking", suffix) == 0)
		printf("%ld\t%ld is thinking\n", time_elapsed, philo.id);
	else if (ft_strcmp("sleeping", suffix) == 0)
		printf("%ld\t%ld is sleeping\n", time_elapsed, philo.id);
	else if (ft_strcmp("eating", suffix) == 0)
		printf("%ld\t%ld is eating\n", time_elapsed, philo.id);
	else if (ft_strcmp("fork", suffix) == 0)
		printf("%ld\t%ld has taken a fork\n", time_elapsed, philo.id);
}

void	kill_philo(t_data *data, unsigned int exit_code)
{
	sem_close(data->forks);
	sem_close(data->print_sem);
	die(data);
	exit(exit_code);
}

void	take_forks(t_data *data, t_philo *philo)
{
	sem_wait(data->forks);
	print_action("fork", data->ms_init, *philo);
	sem_wait(data->forks);
	print_action("fork", data->ms_init, *philo);
}

void	eat(t_data *data, t_philo *philo)
{
	struct timeval	tv;
	time_t			curr_ms;

	print_action("eating", data->ms_init, *philo);
	if (philo->timers.time_to_die < philo->timers.time_to_eat)
	{
		usleep(1000 * philo->timers.time_to_die);
		gettimeofday(&tv, NULL);
		curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		sem_wait(data->print_sem);
		printf("%ld\t%ld died\n", curr_ms - data->ms_init, philo->id);
		kill_philo(data, 1);
	}
}
