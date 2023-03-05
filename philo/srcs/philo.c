/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:49 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/05 16:39:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_time_to_complete(unsigned long long ms)
{
	unsigned long long	starting_time;
	unsigned long long	timer;

	starting_time = getcurrenttime();
	timer = 0;
	while (timer < starting_time)
	{
		timer = starting_time - getcurrenttime();
		usleep(ms / 1000);
	}
}

t_philo	*create_philo(t_main *main, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo *));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->last_meal = 0;
	philo->state = -1;
	pthread_mutex_init(&philo->fork, NULL);
	philo->next_fork = NULL;
	philo->times = main->times;
	philo->prev = NULL;
	philo->next = NULL;
	return (philo);
}

/**
 * return 0 on error
*/
int	add_back(t_main *main, t_philo *philo)
{
	t_philo	*tmp;

	tmp = main->first_philo;
	if (!philo)
		return (0);
	else if (!tmp)
	{
		main->first_philo = philo;
		return (1);
	}
	else if (!main->first_philo->prev)
		main->first_philo->prev = philo;
	else
	{
		tmp = main->first_philo->prev;
		philo->prev = tmp;
		main->first_philo->prev = philo;
	}
	tmp->next = philo;
	tmp->next_fork = &philo->fork;
	philo->next_fork = &main->first_philo->fork;
	philo->next = main->first_philo;
	return (1);
}
