/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:02:11 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/11 20:16:26 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include "libs_bonus.h"
# include "ft_defines.h"

typedef struct s_timer
{
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	last_meal;
}	t_timer;

typedef struct s_philo
{
	size_t	id;
	int		meals;
	t_timer	timers;
}	t_philo;

typedef struct s_data
{
	time_t	ms_init;
	pid_t	*pid;
	size_t	curr_philo;
	t_philo	*philos;
}	t_data;

long int	ft_atol(const char *nptr);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			ft_is_space(char c);
int			is_number(char *str);
int			print_error(int err_code);
int			valid_args(int params, char **args);
time_t		get_ms_timestamp(void);
time_t		micro_to_milli(time_t microseconds);
time_t		sec_to_milli(time_t seconds);
time_t		milli_to_micro(time_t milliseconds);
#endif
