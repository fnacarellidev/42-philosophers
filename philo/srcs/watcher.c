/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:44:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 15:23:03 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	stop_simulation(t_philo_info *philo_info)
{
	int	i;
	int	philo_qty;

	i = 0;
	philo_qty = philo_info->philo_qty;
	while (i < philo_qty)
	{
		philo_info->philo[i].stop_simulation = 1;
		i++;
	}
}

static void	print_and_set_stop_simulation(t_philo philo, t_philo_info *info)
{
	time_t			ms_init;
	time_t			curr_ms;
	struct timeval	tv;

	ms_init = philo.ms_init_timestamp;
	pthread_mutex_lock(info->g_mut);
	gettimeofday(&tv, NULL);
	curr_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	printf("%ld\t%d died\n", curr_ms - ms_init, philo.id);
	stop_simulation(info);
	pthread_mutex_unlock(info->g_mut);
}

static int	has_dead_philo(t_philo_info *info, unsigned int t_to_die)
{
	int				i;
	time_t			ms_init;
	time_t			last_meal;
	unsigned int	n_meals;
	struct timeval	tv;

	i = -1;
	gettimeofday(&tv, NULL);
	ms_init = info->philo[0].ms_init_timestamp;
	while (++i < info->philo_qty)
	{
		pthread_mutex_lock(info->g_mut);
		last_meal = info->philo[0].last_meal;
		n_meals = info->philo[0].info.eat_many_times;
		pthread_mutex_unlock(info->g_mut);
		if (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - last_meal >= t_to_die \
			&& n_meals != 0)
		{
			print_and_set_stop_simulation(info->philo[i], info);
			return (1);
		}
		else if (n_meals == 0)
			return (1);
	}
	return (0);
}

void	*watcher(void *info)
{
	unsigned int	time_to_die;
	t_philo_info	*philo_info;

	philo_info = (t_philo_info *)info;
	time_to_die = philo_info->philo[0].info.time_to_die;
	while (1)
	{
		usleep(200);
		if (has_dead_philo(philo_info, time_to_die))
			return (NULL);
	}
	return (NULL);
}
