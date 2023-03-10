/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:38:18 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/07 17:28:40 by vgroux           ###   ########.fr       */
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
	int					nb_meal_eated;
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
	int					nb_philo;
	pthread_mutex_t		print;
	t_times				*times;
	t_philo				*first_philo;
}	t_main;

/*		MAIN		*/
int					main(int argc, char **argv, char **envp);

/*		INIT		*/
int					init(t_main *main, int argc, char **argv);
t_times				*init_times(int argc, char **argv);

/*		CLEAR		*/
int					clear_main(t_main *main);
int					clear_philo(t_main *main);

/*		ERROR		*/
int					check_input(int argc, char **argv);
int					err(char *str, int flag);

/*		PHILO		*/
t_philo				*create_philo(t_main *main, int id);
int					add_back(t_main *main, t_philo *philo);

/*		TIME		*/
unsigned long long	getcurrenttime(void);
unsigned long long	getrunningtime(t_main *main);

/*		UTILS		*/
int					ft_atoi(char *str);
void print_philo(t_main *main);

#endif