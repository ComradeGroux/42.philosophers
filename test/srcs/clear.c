/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:13:37 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 15:51:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_main(t_main *main)
{
	pthread_mutex_destroy(&main->print);
	free(main->times);
	return (1);
}

int	clear_philo(t_main *main)
{
	t_philo	*tmp;

	if (main->first_philo != NULL)
	{
		tmp = main->first_philo->next;
		if (!tmp)
			free(main->first_philo);
		else
		{
			while (tmp->next != main->first_philo)
			{
				free(tmp->prev);
				pthread_mutex_destroy(&tmp->fork);
				tmp = tmp->next;
			}
		}
	}
	return (clear_main(main));
}
