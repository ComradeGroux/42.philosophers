/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:13 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/14 18:39:09 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (check_arg(argc, argv))
		return (1);
	if (init(&main, argc, argv))
		return (err(ERR_INIT, 0));
	if (!init_thread(&main))
		return (err(ERR_INIT, 0));
	//execute_waiter(&main);
	clear_all(&main);
	return (0);
}
