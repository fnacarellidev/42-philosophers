/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:14:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/11 18:38:26 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

static void	init_philos(t_data *data, size_t philos_qty, char **argv)
{
	size_t	i;
	time_t	init_meal;

	i = 0;
	while (i < philos_qty)
	{
		data->philos[i].id = i + 1;
		data->philos[i].timers.time_to_die = ft_atol(argv[2]);
		data->philos[i].timers.time_to_eat = ft_atol(argv[3]);
		data->philos[i].timers.time_to_sleep = ft_atol(argv[4]);
		if (argv[5])
			data->philos[i].meals = ft_atol(argv[5]);
		else
			data->philos[i].meals = -1;
		i++;
	}
	init_meal = get_ms_timestamp();
	i = 0;
	while (i < philos_qty)
	{
		data->philos[i].timers.last_meal = init_meal;
		i++;
	}
}

void	init_data(t_data *data, size_t philos_qty, char **argv)
{
	size_t	i;

	i = 0;
	data->ms_init = get_ms_timestamp();
	data->philos = malloc(sizeof(t_philo) * philos_qty);
	init_philos(data, philos_qty, argv);
	while (i < philos_qty)
	{
		data->curr_philo = i;
		i++;
	}
}

static void	die(t_data *data)
{
	free(data->philos);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	size_t	philos_qty;

	if (!valid_args(argc - 1, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	philos_qty = (size_t)ft_atol(argv[1]);
	init_data(data, philos_qty, argv);
	die(data);
	return (0);
}
