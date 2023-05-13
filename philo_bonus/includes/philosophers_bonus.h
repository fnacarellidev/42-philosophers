/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:02:11 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/13 18:42:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include "libs_bonus.h"
# include "ft_defines_bonus.h"

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
	pid_t	*pid;
	t_philo	*philos;
	time_t	ms_init;
	size_t	curr_philo;
	sem_t	*forks;
}	t_data;

long int	ft_atol(const char *nptr);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			ft_is_space(char c);
int			is_number(char *str);
int			print_error(int err_code);
int			valid_args(int params, char **args);
int			ft_strcmp(const char *s1, const char *s2);
time_t		get_ms_timestamp(void);
time_t		micro_to_milli(time_t microseconds);
time_t		sec_to_milli(time_t seconds);
time_t		milli_to_micro(time_t milliseconds);
void		init_data(t_data *data, size_t philos_qty, char **argv);
void		die(t_data *data);
void		print_action(char *suffix, time_t init_ms, t_philo philo);
void		take_forks(t_data *data, t_philo *philo);
void		eat(t_data *data, t_philo *philo);
void		solve_single_philo(t_data *data);

#endif
