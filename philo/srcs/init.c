/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:09:01 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/02 18:41:38 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_main *main, int argc, char **argv)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = argv[1];
	init_times(main, argc, argv);
	while (i < nb_philo)
	{
		main->first_philo = ft_philo_add(main);
		i++;
	}
}

void	init_times(t_main *main, int argc, char **argv)
{
	main->times->start_time = getcurrenttime();
	main->times->die_time = ft_atoi(argv[2]);
	main->times->eat_time = ft_atoi(argv[3]);
	main->times->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		main->times->nb_meal = argv[5];
	else
		main->times->nb_meal = -1;
}
