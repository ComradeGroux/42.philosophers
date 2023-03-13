/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/13 13:52:56 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_FEW_ARG "Too few arguments"
# define ERR_MANY_ARG "Too many arguments"
# define ERR_POS_ARG "Arguments must be positive"
# define ERR_INIT "Something happen during the initialisation"

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
	int					nb_meal_ate;
	int					state;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	pthread_t			th;
	t_times				*times;
}	t_philo;

typedef struct s_main
{
	int				nb_thread;
	int				philo_dead;
	pthread_mutex_t	print;
	t_philo			*philo;
	t_times			*times;
}	t_main;

/*		MAIN		*/
int					main(int argc, char **argv);

/*		INIT		*/
int					init(t_main *main, int argc, char **argv);
int					init_main(t_main *main, int argc, char **argv);
t_times				*init_times(int argc, char **argv);
int					init_philo(t_main *main);

/*		THREAD		*/
int					init_thread(t_main *main);
void				join_thread(t_main *main);
void				destroy_mutex(t_main *main);

/*		ROUTINE		*/
void				*routine(void *args);

/*		TIMES		*/
unsigned long long	getcurrenttime(void);
unsigned long long	getrunningtime(t_main *main);

/*		UTILS		*/
int					ft_atoi(char *str);

/*		ERROR		*/
int					check_arg(int argc, char **argv);
int					err(char *str, int flag);

/*		CLEAR		*/
void				clear_all(t_main *main);

#endif