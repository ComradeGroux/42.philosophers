/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:09:01 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/01 16:50:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **argv)
{
	data->start_time = getcurrenttime();
	(void)argv;
	/*
	data->nb_philo = argv[1];
	data->nb_fork = argv[1];
	data->die_time = argv[2];
	data->eat_time = argv[3];
	data->sleep_time = argv[4];
	if (argv[5])
		data->nb_meal = argv[5];
	else
		data->nb_meal = 0;
	*/
}
