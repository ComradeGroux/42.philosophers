/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:06:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/17 15:08:50 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return -1 on error
*/
int	ft_atoi(char *str)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	else if (nb > 2147483647)
		return (-1);
	return (nb);
}

char	*get_state(t_philo *philo)
{
	int	state;

	state = philo->state;
	if (state == DEAD)
		return (STATE_DEAD);
	else if (state == EAT)
		return (STATE_EAT);
	else if (state == FORK)
		return (STATE_FORK);
	else if (state == SLEEP)
		return (STATE_SLEEP);
	else if (state == THINK)
		return (STATE_THINK);
	return (NULL);
}
