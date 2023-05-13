/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:24:50 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 19:55:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"
#include <semaphore.h>

static void	init_timers(t_data *data, size_t philos_qty, char **argv)
{
	size_t			i;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	time_to_die = ft_atol(argv[2]);
	time_to_eat = ft_atol(argv[3]);
	time_to_sleep = ft_atol(argv[4]);
	while (i < philos_qty)
	{
		data->philos[i].timers.time_to_die = time_to_die;
		data->philos[i].timers.time_to_eat = time_to_eat;
		data->philos[i].timers.time_to_sleep = time_to_sleep;
		data->philos[i].timers.last_meal = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		i++;
	}
}

static void	init_philos(t_data *data, size_t philos_qty, char **argv)
{
	size_t	i;

	i = 0;
	init_timers(data, philos_qty, argv);
	while (i < philos_qty)
	{
		data->philos[i].id = i + 1;
		if (argv[5])
			data->philos[i].meals = ft_atol(argv[5]);
		else
			data->philos[i].meals = -1;
		i++;
	}
}

static void	child_proc(t_data *data)
{
	t_philo	philo;
	size_t	i;

	i = data->curr_philo;
	philo = data->philos[i];
	sem_wait(data->forks);
	printf("Philo %ld grabbed a fork!\n", philo.id);
	sem_wait(data->forks);
	printf("Philo %ld grabbed a fork!\n", philo.id);
	printf("Philo %ld started eating!\n", philo.id);
	sleep(2);
	printf("Philo %ld done eating!\n", philo.id);
	sem_post(data->forks);
	sem_post(data->forks);
	die(data);
	exit(1);
}

void	init_data(t_data *data, size_t philos_qty, char **argv)
{
	size_t			i;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	data->ms_init = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	data->philos = malloc(sizeof(t_philo) * philos_qty);
	data->pid = malloc(sizeof(pid_t) * philos_qty);
	if (data->philos == NULL || data->pid == NULL)
		exit(1);
	init_philos(data, philos_qty, argv);
	data->forks = sem_open("/sem_forks", O_CREAT, 0777, philos_qty);
	while (i < philos_qty)
	{
		data->curr_philo = i;
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			child_proc(data);
		i++;
	}
}
