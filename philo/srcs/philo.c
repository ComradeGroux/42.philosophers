/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:34 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/23 12:00:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 on error
*/
int	philo_eat(t_main *main, t_philo *philo)
{
	if (is_dead_eat_time(philo) || pthread_mutex_lock(&philo->fork))
		return (1);
	if (is_dead_eat_time(philo) || pthread_mutex_lock(philo->next_fork))
		return (1);
	if (main->philo_dead || is_dead_eat_time(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		return (1);
	}
	philo->state = EAT;
	if (print_status(main, philo, 0))
		return (1);
	philo->last_meal = getcurrenttime();
	usleep(main->times->eat_time * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	philo->last_meal = getcurrenttime();
	philo->nb_meal_ate++;
	return (0);
}

/**
 * Return 1 on error
*/
int	philo_sleep(t_main *main, t_philo *philo)
{
	philo->state = SLEEP;
	if (is_dead_eat_time(philo) || print_status(main, philo, 0))
		return (1);
	usleep(main->times->sleep_time * 1000);
	return (0);
}

/**
 * Return 1 on error
*/
int	philo_think(t_main *main, t_philo *philo)
{
	philo->state = THINK;
	if (is_dead_eat_time(philo) || print_status(main, philo, 0))
		return (1);
	return (0);
}
