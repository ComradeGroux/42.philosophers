/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:13 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/20 18:26:53 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_exit(t_main *main)
{
	clear_all(main);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	(void)i;
	if (check_arg(argc, argv))
		return (1);
	if (init(&main, argc, argv))
		return (err(ERR_INIT, 0));
	if (!init_thread(&main))
		return (err(ERR_INIT, 0));
	if (main.times->nb_meal > 0)
		while (main.philo_dead == 0)
			;
	else
	{
		;
	}
	join_thread(&main);
	clear_all(&main);
	return (0);
}
