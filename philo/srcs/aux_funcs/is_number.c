/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:50:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/03 16:25:18 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers.h"

int	is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (ft_is_sign(str[i]))
		i++;
	if (!ft_is_digit(str[i]))
		return (0);
	while (ft_is_digit(str[i]))
		i++;
	while (ft_is_space(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}
