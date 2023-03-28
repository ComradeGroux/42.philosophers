/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:45:39 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 15:34:27 by vgroux           ###   ########.fr       */
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
	i = 1;
	while (i <= main->nb_thread)
		pthread_mutex_destroy(&main->philo[i++].fork);
}

void	join_thread(t_main *main)
{
	int	i;

	i = 1;
	while (i <= main->nb_thread)
	{
		pthread_join(main->philo[i].th, NULL);
		i++;
	}
}

void	fork_lock(t_main *main, t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	philo->state = FORK;
	print_status(main, philo, 0);
	pthread_mutex_lock(philo->next_fork);
	print_status(main, philo, 0);
}

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}
