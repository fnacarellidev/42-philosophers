/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:53:16 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/13 15:11:32 by fnacarel         ###   ########.fr       */
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
		print_action("fork", data);
		usleep(data->philos[0].timers.time_to_die * 1000);
		gettimeofday(&tv, NULL);
		curr_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		printf("%ld\t1 died\n", curr_ms - data->ms_init);
		sem_post(data->forks);
		die(data);
		exit(0);
	}
}
