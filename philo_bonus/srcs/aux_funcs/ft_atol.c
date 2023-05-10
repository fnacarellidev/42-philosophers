/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:07:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/10 20:07:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers_bonus.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_is_space(*(nptr + i)))
		i++;
	if (!ft_is_digit(*(nptr + i)) && !ft_is_sign(*(nptr + i)))
		return (res);
	if (ft_is_sign(*(nptr + i)))
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_digit(*(nptr + i)))
	{
		res = ((res * 10) + (*(nptr + i) - '0') * sign);
		i++;
	}
	return (res);
}

