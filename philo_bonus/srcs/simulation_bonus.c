/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:53:16 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/16 17:24:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

void	solve_single_philo(t_data *data)
{
	struct timeval	tv;
	pid_t			pid;
	time_t			curr_ms;

	data->curr_philo = 0;
	pid = fork();
	if (pid == 0)
	{
		sem_wait(data->forks);
		print_action("fork", data->ms_init, data->philos[0]);
		usleep(data->philos[0].timers.time_to_die * 1000);
		gettimeofday(&tv, NULL);
		curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		printf("%ld\t1 died\n", curr_ms - data->ms_init);
		sem_post(data->forks);
		die(data);
		exit(0);
	}
}

static void	run_simulation(t_data *data)
{
	t_philo	philo;

	philo = data->philos[data->curr_philo];
	while (1)
	{
		take_forks(data, &philo);
		eat(data, &philo);
		drop_forks(data);
		rest(data, &philo);
	}
}

void	solve_n_philos(t_data *data, size_t philos_qty)
{
	size_t	i;

	i = 0;
	while (i < philos_qty)
	{
		data->curr_philo = i;
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			run_simulation(data);
		i++;
	}
}
