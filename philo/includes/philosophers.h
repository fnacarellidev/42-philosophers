/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:53:04 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 16:32:20 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define EPARAM 1
# define ENOTNUMPARAM 2
# define ELESSZERO 3
# define EINTRANGE 4
# define EPHILO 5
# define PH_MAX_INT 2147483647
# include "libs.h"

int			is_number(char *str);
int			ft_is_space(char c);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			print_error(int err_code);
int			valid_args(int params, char **args);
long int	ft_atol(const char *nptr);

#endif
