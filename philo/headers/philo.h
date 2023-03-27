/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:50:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/24 15:26:21 by vgroux           ###   ########.fr       */
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

# define INIT -1
# define DEAD 0
# define STATE_DEAD "died"
# define EAT 1
# define STATE_EAT "is eating"
# define FORK 2
# define STATE_FORK "has taken a fork"
# define SLEEP 3
# define STATE_SLEEP "is sleeping"
# define THINK 4
# define STATE_THINK "is thinking"

# define ERR_FEW_ARG "Too few arguments"
# define ERR_MANY_ARG "Too many arguments"
# define ERR_POS_ARG "Arguments must be positive"
# define ERR_INIT "Something happen during the initialisation"
# define ERR_NB_PHILO "At least one philosopher must be present"

typedef struct s_times
{
	unsigned long long	die_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	int					nb_meal;
	unsigned long long	start_time;
	pthread_mutex_t		mutex_times;
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
	int				id_philo;
	int				philo_dead;
	pthread_mutex_t	print;
	pthread_mutex_t	init;
	pthread_mutex_t	mutex_dead;
	t_philo			*philo;
	t_times			*times;
}	t_main;

/*		MAIN		*/
int					main(int argc, char **argv);
int					only_one(t_main *main);
int					every_philo_enough_ate(t_main *main);
void				infinite_loop(t_main *main);

/*		INIT		*/
int					init(t_main *main, int argc, char **argv);
int					init_main(t_main *main, int argc, char **argv);
t_times				*init_times(int argc, char **argv);
int					init_philo(t_main *main);
int					init_thread(t_main *main);

/*		THREAD		*/
void				join_thread(t_main *main);
void				destroy_mutex(t_main *main);

/*		ROUTINE		*/
int					routine_execute(t_main *main, t_philo *philo);
void				*routine(void *args);

/*		PHILO		*/
int					philo_eat(t_main *main, t_philo *philo);
int					philo_sleep(t_main *main, t_philo *philo);
int					philo_think(t_main *main, t_philo *philo);

/*		TIMES		*/
unsigned long long	getcurrenttime(void);
unsigned long long	getrunningtime(t_main *main);
unsigned long long	deltatime(t_main *main);
void				nsleep(unsigned long long to_wait);

/*		UTILS		*/
int					ft_atoi(char *str);
char				*get_state(t_philo *philo);
int					print_status(t_main *main, t_philo *philo, int f);
int					is_dead_eat_time(t_philo *philo);
int					print_info(t_main *main, int philo_id, char *str);

/*		ERROR		*/
int					check_arg(int argc, char **argv);
int					err(char *str, int flag);

/*		CLEAR		*/
void				clear_all(t_main *main);
int					clear_exit(t_main *main);

#endif