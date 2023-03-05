/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:09:01 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/05 16:37:32 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return 0 if everything is OK
*/
int	init(t_main *main, int argc, char **argv)
{
	int		i;
	int		nb_philo;
	t_philo	*philo;

	i = 0;
	nb_philo = ft_atoi(argv[1]);
	main->first_philo = NULL;
	pthread_mutex_init(main->print, NULL);
	main->times = init_times(argc, argv);
	if (!main->times)
		return (clear_main(main));
	main->nb_fork = nb_philo;
	while (i < nb_philo)
	{
		philo = create_philo(main, i++);
		if (!philo || !add_back(main, philo))
			return (clear_philo(main));
	}
	return (0);
}

t_times	*init_times(int argc, char **argv)
{
	t_times	*times;

	times = malloc(sizeof(t_times *));
	if (!times)
		return (NULL);
	times->start_time = getcurrenttime();
	times->die_time = ft_atoi(argv[2]);
	times->eat_time = ft_atoi(argv[3]);
	times->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		times->nb_meal = ft_atoi(argv[5]);
	else
		times->nb_meal = 0;
	return (times);
}
