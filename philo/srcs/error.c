/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:17 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/01 16:45:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return 1 if the inputs are OK
 * return 0 if the inputs are wrong
*/
int	check_input(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (0);
	return (1);
}
