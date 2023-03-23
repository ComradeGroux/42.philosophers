/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:06:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/23 14:17:27 by vgroux           ###   ########.fr       */
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

int	print_status(t_main *main, t_philo *philo, int f)
{
	char	*str;

	if (f)
	{
		printf("%llu %i %s\n", deltatime(main), philo->id, STATE_DEAD);
		main->philo_dead++;
	}
	else if (!philo)
	{
		print_info(main, 0, STATE_DEAD);
		return (1);
	}
	else
	{
		str = get_state(philo);
		if (!str)
			return (1);
		return (print_info(main, philo->id, str));
	}
	return (0);
}

/**
 * Return 1 if the philosopher is dead
*/
int	is_dead_eat_time(t_philo *philo)
{
	if (getcurrenttime() - philo->last_meal > philo->times->die_time)
		return (1);
	return (0);
}

int	print_info(t_main *main, int philo_id, char *str)
{
	pthread_mutex_lock(&main->print);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->print);
		return (1);
	}
	printf("%llu %i %s\n", deltatime(main), philo_id, str);
	pthread_mutex_unlock(&main->print);
	return (0);
}
