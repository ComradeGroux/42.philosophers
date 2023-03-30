/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/30 11:26:36 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 if the philo die
*/
int	routine_execute(t_main *main, t_philo *philo)
{
	if (is_dead_eat_time(main, philo))
	{
		philo->state = DEAD;
		print_status(main, philo, 1);
		pthread_mutex_lock(&main->mutex_dead);
		main->philo_dead++;
		pthread_mutex_unlock(&main->mutex_dead);
		return (1);
	}
	else
	{
		if (philo_eat(main, philo))
			return (1);
		if (philo->nb_meal_ate != main->times->nb_meal)
		{
			if (philo_sleep(main, philo))
				return (1);
			if (philo_think(main, philo))
				return (1);
		}
	}
	return (0);
}

void	*routine(void *args)
{
	t_main	*main;
	t_philo	*philo;
	t_times	*times;

	philo = args;
	main = philo->main;
	times = main->times;
	if (times->nb_meal >= 0)
	{
		while (philo->nb_meal_ate < times->nb_meal && isdead(main))
			routine_execute(main, philo);
	}
	else
	{
		while (isdead(main))
			if (routine_execute(main, philo))
				break ;
	}
	return (NULL);
}

int	isdead(t_main *main)
{
	pthread_mutex_lock(&main->mutex_dead);
	if (!main->philo_dead)
	{
		pthread_mutex_unlock(&main->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&main->mutex_dead);
	return (0);
}
