/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:34 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 14:36:52 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 on error
*/
int	philo_eat(t_main *main, t_philo *philo)
{
	if (is_dead_eat_time(main, philo) || pthread_mutex_lock(&philo->fork))
		return (1);
	philo->state = FORK;
	print_status(main, philo, 0);
	if (is_dead_eat_time(main, philo) || pthread_mutex_lock(philo->next_fork))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	print_status(main, philo, 0);
	if (main->philo_dead || is_dead_eat_time(main, philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		return (1);
	}
	philo->state = EAT;
	if (print_status(main, philo, 0))
		return (1);
	philo->last_meal = getcurrenttime(main);
	nsleep(philo->times->eat_time);
	philo->last_meal = getcurrenttime(main);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
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
