/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:14:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 19:57:27 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	size_t	i;
	t_data	*data;
	size_t	philos_qty;

	i = 0;
	if (!valid_args(argc - 1, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	philos_qty = (size_t)ft_atol(argv[1]);
	init_data(data, philos_qty, argv);
	while (i < philos_qty)
	{
		wait(NULL);
		i++;
	}
	die(data);
	return (0);
}

void	die(t_data *data)
{
	sem_unlink("/sem_forks");
	free(data->pid);
	free(data->philos);
	free(data);
}
