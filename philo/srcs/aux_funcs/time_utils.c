/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:40:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 14:20:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philosophers.h"

time_t	get_ms_timestamp(void)
{
	struct timeval	tv;
	time_t			ms_timestamp;

	gettimeofday(&tv, NULL);
	ms_timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
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
