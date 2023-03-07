/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:08 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 17:27:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv, char **envp)
{
	t_main	main;

	(void)envp;
	if (check_input(argc, argv))
	{
		if (init(&main, argc, argv))
		{
			clear_main(&main);
			return (err(INIT_ERROR, 0));
		}
		print_philo(&main);
	}
	return (0);
}

/**
 * print the status of a philosopher
*/
void	philo_change(t_main *main, int id_philo, char *status)
{
	pthread_mutex_lock(&main->print);
	printf("%llu %i %s\n", getrunningtime(main), id_philo, status);
	pthread_mutex_unlock(&main->print);
}
