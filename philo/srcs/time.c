/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:16:55 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/22 16:31:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return the actual time in ms
*/
unsigned long long	getcurrenttime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

/**
 * return the running time in ms
*/
unsigned long long	getrunningtime(t_main *main)
{
	return (getcurrenttime() - main->times->start_time);
}

unsigned long long	deltatime(t_main *main)
{
	return (getcurrenttime() - main->times->start_time);
}
