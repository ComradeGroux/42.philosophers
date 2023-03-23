/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:13 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/23 11:58:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	(void)i;
	if (check_arg(argc, argv))
		return (1);
	if (init(&main, argc, argv))
		return (err(ERR_INIT, 0));
	if (main.nb_thread == 1)
		return (only_one(&main));
	if (!init_thread(&main))
		return (err(ERR_INIT, 0));
	if (main.times->nb_meal > 0)
		while (main.philo_dead == 0)
			;
	else
	{
		while (main.philo_dead == 0)
		{
			i = 0;
			while (i < main.nb_thread)
			{
				if (is_dead_eat_time(&main.philo[i]))
				{
					print_status(&main, &main.philo[i], 1);
					main.philo_dead++;
					break ;
				}
				i++;
			}
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
