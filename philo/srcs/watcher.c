/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:44:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/09 16:44:38 by fnacarel         ###   ########.fr       */
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

void	*philos_watcher(void *info)
{
	int				i;
	unsigned int	time_to_die;
	t_philo			*curr_philo;
	t_philo_info	*philo_info;

	philo_info = (t_philo_info *)info;
	while (1)
	{
		i = 0;
		while (i < philo_info->philo_qty)
		{
			curr_philo = philo_info->philo + i;
			time_to_die = curr_philo->info.time_to_die;
			if (get_ms_timestamp() - curr_philo->last_meal >= time_to_die && curr_philo->info.eat_many_times != 0)
			{
				pthread_mutex_lock(philo_info->g_mut);
				printf("%ld %d died\n", get_ms_timestamp() - curr_philo->ms_init_timestamp, curr_philo->id);
				stop_simulation(philo_info);
				pthread_mutex_unlock(philo_info->g_mut);
				return (NULL);
			}
			else if (curr_philo->info.eat_many_times == 0)
				return (NULL);
		}
	}
	return (NULL);
}
