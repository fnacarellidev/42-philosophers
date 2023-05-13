/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:22:19 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/11 12:22:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers_bonus.h"

time_t	get_ms_timestamp(void)
{
	struct timeval	tv;
	time_t			ms_timestamp;

	gettimeofday(&tv, NULL);
	ms_timestamp = sec_to_milli(tv.tv_sec) + micro_to_milli(tv.tv_usec);
	return (ms_timestamp);
}

time_t	micro_to_milli(time_t microseconds)
{
	return (microseconds / 1000);
}

time_t	sec_to_milli(time_t seconds)
{
	return (seconds * 1000);
}

time_t	milli_to_micro(time_t milliseconds)
{
	return (milliseconds * 1000);
}
