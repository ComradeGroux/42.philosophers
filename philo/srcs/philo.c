/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:34 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 14:58:57 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 on error
*/
int	philo_eat(t_main *main, t_philo *philo)
{
	fork_lock(main, philo);
	if (main->philo_dead || is_dead_eat_time(main, philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		return (1);
	}
	philo->state = EAT;
	if (print_status(main, philo, 0))
		return (1);
	pthread_mutex_lock(&main->times->mutex_times);
	philo->last_meal = getcurrenttime(main);
	pthread_mutex_unlock(&main->times->mutex_times);
	nsleep(philo->times->eat_time);
	pthread_mutex_lock(&main->times->mutex_times);
	philo->last_meal = getcurrenttime(main);
	pthread_mutex_unlock(&main->times->mutex_times);
	fork_unlock(philo);
	philo->nb_meal_ate++;
	return (0);
}

/**
 * Return 1 on error
*/
int	philo_sleep(t_main *main, t_philo *philo)
{
	philo->state = SLEEP;
	if (is_dead_eat_time(main, philo) || print_status(main, philo, 0))
		return (1);
	nsleep(main->times->sleep_time);
	return (0);
}

/**
 * Return 1 on error
*/
int	philo_think(t_main *main, t_philo *philo)
{
	philo->state = THINK;
	if (is_dead_eat_time(main, philo) || print_status(main, philo, 0))
		return (1);
	return (0);
}
