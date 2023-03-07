/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:06:53 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 18:32:38 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Check the input
 * return 0 if their are OK
*/
int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		if (argc < 5)
			return (err(ERR_FEW_ARG, 1));
		else
			return (err(ERR_MANY_ARG, 1));
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
		{
			err(ERR_POS_ARG, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * flag = print how to execute the application
*/
int	err(char *str, int flag)
{
	printf("philo: error: %s\n", str);
	if (flag)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	}
	return (1);
}
