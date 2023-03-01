/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:08 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/01 17:20:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)envp;
	if (check_input(argc, argv))
	{
		init_data(&data, argv);
	}
	return (0);
}

/**
 * print the status of a philosopher
*/
void	philo_change(t_data *data, int id_philo, char *status)
{
	printf("%llu %i %s\n", getrunningtime(data), id_philo, status);
}
