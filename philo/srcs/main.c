/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:13 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/23 14:23:45 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	if (check_arg(argc, argv))
		return (1);
	if (init(&main, argc, argv))
		return (err(ERR_INIT, 0));
	if (main.nb_thread == 1)
		return (only_one(&main));
	if (!init_thread(&main))
		return (err(ERR_INIT, 0));
	if (main.times->nb_meal > 0)
		while (main.philo_dead == 0 && every_philo_enough_ate(&main))
			;
	else
	{
		i = 0;
		while (main.philo_dead == 0 && i < main.nb_thread)
		{
			if (is_dead_eat_time(&main.philo[i]))
			{
				print_status(&main, &main.philo[i], 1);
				break ;
			}
			i++;
			if (i == main.nb_thread)
				i = 0;
		}
	}
	join_thread(&main);
	clear_all(&main);
	return (0);
}

int	only_one(t_main *main)
{
	usleep(main->times->die_time * 1000);
	print_status(main, NULL, 0);
	return (1);
}

int	every_philo_enough_ate(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nb_thread)
	{
		if (main->philo[i].nb_meal_ate < main->times->nb_meal)
			return (1);
		i++;
	}
	return (0);
}
