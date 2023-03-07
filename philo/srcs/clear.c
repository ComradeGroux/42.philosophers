/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:37:54 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 18:42:09 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_main *main)
{
	int	i;

	free(main->times);
	pthread_mutex_destroy(&main->print);
	i = 0;
	while (i < main->nb_thread)
		pthread_mutex_destroy(&main->philo[i++].fork);
	free(main->philo);
}
