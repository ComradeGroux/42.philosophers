/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/14 18:51:28 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main *main;

	main = (t_main *)args;
	printf("Thread id: %i\n", main->id_philo);
	return (NULL);
}

void	print_status(t_main *main)
{
	pthread_mutex_lock(main->print);
	printf("%llu %i %s\n", getcurrenttime(), main->id_philo, get_state(main));
	pthread_mutex_unlock(main->print);
}
