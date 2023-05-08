/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:40:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/08 12:25:49 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers.h"

unsigned int	get_ms_timestamp(void)
{
	struct timeval	tv;
	unsigned int	ms_timestamp;

	gettimeofday(&tv, NULL);
	ms_timestamp = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	return (ms_timestamp);
}

unsigned int	micro_to_milli(unsigned int microseconds)
{
	return (microseconds / 1000);
}

unsigned int	sec_to_milli(unsigned int seconds)
{
	return (seconds * 1000);
}

unsigned int	milli_to_micro(unsigned int milliseconds)
{
	return (milliseconds * 1000);
}
