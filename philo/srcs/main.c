/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:13 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 18:42:54 by vgroux           ###   ########.fr       */
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
	printf("Init OK\n");
	return (0);
}
