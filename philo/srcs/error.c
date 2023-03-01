/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:17 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/01 17:24:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return 1 if the inputs are OK
 * return 0 if the inputs are wrong
*/
int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		err("Too many or too few arguments", 1);
		return (0);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
		{
			err("Arguments must be positif number", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * flag = print how to exe
*/
void	err(char *str, int flag)
{
	printf("philo: error: %s\n", str);
	if (flag)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	}
}
