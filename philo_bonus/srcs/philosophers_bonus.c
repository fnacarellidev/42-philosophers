/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:14:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/17 18:16:20 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

static void	loop_wait(t_data *data, size_t philos_qty);
static int	less_than_zero_param(t_data *data);

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
	if (less_than_zero_param(data))
	{
		die(data);
		exit(1);
	}
	if (philos_qty == 1)
		solve_single_philo(data);
	else
		solve_n_philos(data, philos_qty);
	loop_wait(data, philos_qty);
	die(data);
	return (0);
}

static void	kill_childs(t_data *data, size_t philos_qty)
{
	pid_t	pid;
	size_t	i;

	i = 0;
	while (i < philos_qty)
	{
		pid = data->pid[i];
		kill(pid, SIGKILL);
		i++;
	}
}

static void	loop_wait(t_data *data, size_t philos_qty)
{
	size_t	i;
	int		exit_status;

	i = 1;
	waitpid(-1, &exit_status, 0);
	if (philos_qty == 1)
		return ;
	exit_status = WEXITSTATUS(exit_status);
	while (i < philos_qty && exit_status == 0)
	{
		waitpid(-1, &exit_status, 0);
		exit_status = WEXITSTATUS(exit_status);
		i++;
	}
	if (exit_status == 1)
		kill_childs(data, philos_qty);
}

static int	less_than_zero_param(t_data *data)
{
	t_philo	philo;

	philo = data->philos[0];
	if (philo.timers.time_to_die < 1 || philo.timers.time_to_eat < 1 \
			|| philo.timers.time_to_sleep < 1)
	{
		write(2, "Timers should be bigger than zero.\n", 35);
		return (1);
	}
	return (0);
}

void	die(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_sem);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	free(data->pid);
	free(data->philos);
	free(data);
}
