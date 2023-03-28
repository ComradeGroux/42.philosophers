/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:58:09 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 15:41:11 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_main *main, int argc, char **argv)
{
	if (init_main(main, argc, argv))
		return (err(ERR_INIT, 0));
	init_philo(main);
	return (0);
}

int	init_main(t_main *main, int argc, char **argv)
{
	main->nb_thread = ft_atoi(argv[1]);
	main->philo = malloc(sizeof(t_philo) * (main->nb_thread + 1));
	if (!main->philo)
		return (1);
	pthread_mutex_init(&main->print, NULL);
	pthread_mutex_init(&main->init, NULL);
	pthread_mutex_init(&main->mutex_dead, NULL);
	main->times = init_times(argc, argv);
	if (!main->times)
	{
		pthread_mutex_destroy(&main->print);
		pthread_mutex_destroy(&main->init);
		pthread_mutex_destroy(&main->mutex_dead);
		free(main->philo);
		return (1);
	}
	main->philo_dead = 0;
	return (0);
}

t_times	*init_times(int argc, char **argv)
{
	t_times	*times;

	times = malloc(sizeof(t_times));
	if (!times)
		return (NULL);
	times->die_time = ft_atoi(argv[2]);
	times->eat_time = ft_atoi(argv[3]);
	times->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		times->nb_meal = ft_atoi(argv[5]);
	else
		times->nb_meal = INIT;
	times->start_time = getcurrenttime();
	pthread_mutex_init(&times->mutex_times, NULL);
	return (times);
}

int	init_philo(t_main *main)
{
	int	i;

	i = 1;
	while (i <= main->nb_thread)
	{
		main->philo[i].id = i;
		main->philo[i].last_meal = main->times->start_time;
		main->philo[i].nb_meal_ate = 0;
		main->philo[i].state = INIT;
		main->philo[i].times = main->times;
		if (pthread_mutex_init(&main->philo[i++].fork, NULL) != 0)
			return (0);
	}
	i = 1;
	while (i < main->nb_thread)
	{
		main->philo[i].next_fork = &main->philo[i + 1].fork;
		i++;
	}
	main->philo[i].next_fork = &main->philo[0].fork;
	return (1);
}

int	init_thread(t_main *main)
{
	int	i;

	i = 1;
	while (i <= main->nb_thread)
	{
		pthread_mutex_lock(&main->init);
		main->id_philo = i;
		if (pthread_create(&main->philo[i].th, NULL, &routine, (void *)main))
			return (0);
		nsleep(1);
		i++;
		pthread_mutex_unlock(&main->init);
	}
	return (1);
}
