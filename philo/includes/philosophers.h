/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:53:04 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/04 15:48:36 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define PH_MAX_INT 2147483647
# include "libs.h"
# include "ft_errors.h"

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*fork_left;
	pthread_t		thread;
	pthread_mutex_t	*g_mut;
}	t_philo;

int			ft_is_sign(char c);
int			ft_is_space(char c);
int			ft_is_digit(char c);
int			is_number(char *str);
int			print_error(int err_code);
int			valid_args(int params, char **args);
long int	ft_atol(const char *nptr);

#endif
