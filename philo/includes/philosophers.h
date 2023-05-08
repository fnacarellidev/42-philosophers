/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:53:04 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/08 12:44:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define PH_MAX_INT 2147483647
# include "libs.h"
# include "ft_errors.h"

typedef struct s_info
{
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				eat_many_times;
}	t_info;

typedef struct s_philo
{
	int					id;
	t_info				info;
	unsigned long int	ms_init_timestamp;
	pthread_mutex_t		fork;
	pthread_mutex_t		*fork_left;
	pthread_t			thread;
	pthread_mutex_t		*g_mut;
}	t_philo;

int				ft_is_sign(char c);
int				ft_is_space(char c);
int				ft_is_digit(char c);
int				is_number(char *str);
int				print_error(int err_code);
int				valid_args(int params, char **args);
long int		ft_atol(const char *nptr);
void			init_philos(t_philo **ptr_address, int philos_qty, char **argv);
unsigned int	sec_to_milli(unsigned int seconds);
unsigned int	milli_to_micro(unsigned int milliseconds);
unsigned int	micro_to_milli(unsigned int microseconds);
unsigned int	get_ms_timestamp(void);

#endif
