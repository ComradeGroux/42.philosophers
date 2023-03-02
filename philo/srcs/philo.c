/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:49 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/02 18:47:57 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_time_to_complete(unsigned long long ms)
{
	unsigned long long	starting_time;
	unsigned long long	timer;

	starting_time = getcurrenttime();
	timer = 0;
	while (timer < starting_time)
	{
		timer = starting_time - getcurrenttime();
		usleep(ms / 1000);
	}
}
