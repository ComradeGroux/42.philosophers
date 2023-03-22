/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:37:54 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/22 16:27:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_main *main)
{
	destroy_mutex(main);
	free(main->times);
	free(main->philo);
}

int	clear_exit(t_main *main)
{
	clear_all(main);
	return (0);
}
