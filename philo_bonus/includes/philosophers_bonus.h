/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:02:11 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/11 12:23:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include "libs_bonus.h"
# include "ft_defines.h"

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
