/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:14:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/13 18:52:13 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

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

int	main(int argc, char **argv)
{
	size_t	i;
	t_data	*data;
	size_t	philos_qty;

	i = -1;
	if (!valid_args(argc - 1, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	philos_qty = (size_t)ft_atol(argv[1]);
	init_data(data, philos_qty, argv);
	if (philos_qty == 1)
		solve_single_philo(data);
	else
		solve_n_philos(data, philos_qty);
	while (++i < philos_qty)
		waitpid(-1, NULL, 0);
	die(data);
	return (0);
}

void	die(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("/sem_forks");
	free(data->pid);
	free(data->philos);
	free(data);
}
