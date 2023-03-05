/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:38:18 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/03 14:40:21 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_times
{
	unsigned long long	die_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	int					nb_meal;
	unsigned long long	start_time;
}	t_times;

typedef struct s_philo
{
	int					id;
	unsigned long long	last_meal;
	int					state;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	pthread_t			th;
	t_times				*times;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

typedef struct s_main
{
	int					nb_fork;
	pthread_mutex_t		*print;
	t_times				*times;
	t_philo				*first_philo;
}	t_main;

/*		MAIN		*/
int					main(int argc, char **argv, char **envp);

/*		INIT		*/

/*		ERROR		*/
int					check_input(int argc, char **argv);
int					err(char *str, int flag);

/*		TIME		*/
unsigned long long	getcurrenttime(void);
unsigned long long	getrunningtime(t_main *main);

/*		UTILS		*/
int					ft_atoi(char *str);

#endif