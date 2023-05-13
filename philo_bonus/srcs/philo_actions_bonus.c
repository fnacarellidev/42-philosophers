/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:02:55 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/13 14:19:15 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

void	print_action(char *suffix, t_data *data)
{
	struct timeval	tv;
	size_t			id;
	time_t			init_timestamp;
	time_t			curr_ms;

	gettimeofday(&tv, NULL);
	curr_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	id = data->philos[data->curr_philo].id;
	init_timestamp = data->ms_init;
	if (ft_strcmp("thinking", suffix) == 0)
		printf("%ld\t%ld is thinking\n", curr_ms - init_timestamp, id);
	else if (ft_strcmp("sleeping", suffix) == 0)
		printf("%ld\t%ld is sleeping\n", curr_ms - init_timestamp, id);
	else if (ft_strcmp("eating", suffix) == 0)
		printf("%ld\t%ld is eating\n", curr_ms - init_timestamp, id);
	else if (ft_strcmp("fork", suffix) == 0)
		printf("%ld\t%ld has taken a fork\n", \
				curr_ms - init_timestamp, id);
}
