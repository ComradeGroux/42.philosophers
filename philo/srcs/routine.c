/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/17 13:38:04 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;
	t_philo	*philo;
	t_times	*times;

	main = (t_main *)args;
	times = main->times;
	philo = &main->first_philo[main->nb_philo];
	printf("Thread id: %i\n", main->id_philo);
	if (times->nb_meal > 0)
	{
		while (philo->nb_meal_eated < times->nb_meal)
			routine_execute(main, philo);
	}
	else
	{
	}
	return (NULL);
}

void	print_status(t_main *main)
{
	char	*str;

	str = get_state(main);
	if (!str)
		return ;
	pthread_mutex_lock(&main->print);
	printf("%llu %i %s\n", getcurrenttime(), main->id_philo, str);
	pthread_mutex_unlock(&main->print);
}
