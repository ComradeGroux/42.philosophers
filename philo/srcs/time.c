/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:16:55 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 14:32:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return the actual time in ms
*/
unsigned long long	getcurrenttime(t_main *main)
{
	struct timeval	tv;

	if (main == NULL)
		gettimeofday(&tv, NULL);
	else
	{
		pthread_mutex_lock(&main->times->mutex_times);
		gettimeofday(&tv, NULL);
		pthread_mutex_unlock(&main->times->mutex_times);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

/**
 * return the running time in ms
*/
unsigned long long	getrunningtime(t_main *main)
{
	return (getcurrenttime(main) - main->times->start_time);
}

unsigned long long	deltatime(t_main *main)
{
	return (getcurrenttime(main) - main->times->start_time);
}

void	nsleep(unsigned long long time)
{
	unsigned long long	target;

	target = getcurrenttime(NULL) + time;
	while (getcurrenttime(NULL) < target)
	{
		usleep(5);
	}
}
