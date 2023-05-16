/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:24:50 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/16 17:07:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

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
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	data->forks = sem_open("/sem_forks", O_CREAT, 0777, philos_qty);
	data->print_sem = sem_open("/sem_print", O_CREAT, 0777, 1);
}
