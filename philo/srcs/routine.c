/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/17 16:53:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Return 1 if the philo die
*/
int	routine_execute(t_main *main, t_philo *philo)
{
	if (getcurrenttime() - philo->last_meal > main->times->die_time)
	{
		main->philo_dead = 1;
		philo->state = DEAD;
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

	main = (t_main *)args;
	times = main->times;
	philo = &main->philo[main->id_philo];
	printf("Thread id: %i\n", main->id_philo);
	if (times->nb_meal > 0)
	{
		while (philo->nb_meal_ate < times->nb_meal && !main->philo_dead)
			routine_execute(main, philo);
	}
	else
	{
		while (!main->philo)
			if (routine_execute(main, philo))
				break ;
	}
	return (NULL);
}

void	print_status(t_main *main, t_philo *philo)
{
	char	*str;

	str = get_state(philo);
	if (!str)
		return ;
	pthread_mutex_lock(&main->print);
	printf("%llu %i %s\n", getcurrenttime(), main->id_philo, str);
	pthread_mutex_unlock(&main->print);
}
