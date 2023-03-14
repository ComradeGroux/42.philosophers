/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:45:39 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/14 17:44:24 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nb_thread)
	{
		main->id_philo = i;
		if (pthread_create(&main->philo[i].th, NULL, &routine, (void *)main) != 0)
			return (0);
		usleep(10);
		i++;
	}
	return (1);
}

void	destroy_mutex(t_main *main)
{
	int	i;

	pthread_mutex_destroy(&main->print);
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
