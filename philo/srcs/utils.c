/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:06:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/13 13:54:16 by vgroux           ###   ########.fr       */
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
