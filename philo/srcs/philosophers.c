/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:55:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 18:52:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philosophers.h"

static void	init_table(t_table *table, char **argv)
{
	table->nbr_of_philos = ft_atol(argv[1]);
}

int	main(int argc, char **argv)
{
	t_table		table;

	if (!valid_args(argc - 1, argv))
		return (1);
	init_table(&table, argv);
	return (0);
}
