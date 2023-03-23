/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/23 11:55:08 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 if the philo die
*/
int	routine_execute(t_main *main, t_philo *philo)
{
	if (is_dead_eat_time(philo))
	{
		philo->state = DEAD;
		print_status(main, philo, 1);
		main->philo_dead++;
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

	main = args;
	times = main->times;
	philo = &main->philo[main->id_philo];
	if (times->nb_meal >= 0)
	{
		while (philo->nb_meal_ate < times->nb_meal && !main->philo_dead)
			routine_execute(main, philo);
	}
	else
	{
		while (!main->philo_dead)
			if (routine_execute(main, philo))
				break ;
	}
	return (NULL);
}
