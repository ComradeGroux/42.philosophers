/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:45:39 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/24 15:27:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_main *main)
{
	int	i;

	pthread_mutex_destroy(&main->init);
	pthread_mutex_destroy(&main->print);
	pthread_mutex_destroy(&main->mutex_dead);
	pthread_mutex_destroy(&main->times->mutex_times);
	i = 0;
	while (i < main->nb_thread)
		pthread_mutex_destroy(&main->philo[i++].fork);
}

void	join_thread(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nb_thread)
	{
		pthread_join(main->philo[i].th, NULL);
		i++;
	}
}
