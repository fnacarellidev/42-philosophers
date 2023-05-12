/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:40:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/05/12 17:26:39 by fnacarel         ###   ########.fr       */
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
