/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:38:18 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/01 17:19:27 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_data
{
	unsigned long long	start_time;
	int					nb_philo;
	int					nb_fork;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					nb_meal;
}	t_data;

/*		MAIN		*/
int					main(int argc, char **argv, char **envp);

/*		INIT		*/
void				init_data(t_data *data, char **argv);

/*		ERROR		*/
int					check_input(int argc, char **argv);
void				err(char *str, int flag);

/*		TIME		*/
unsigned long long	getcurrenttime(void);
unsigned long long	getrunningtime(t_data *data);

/*		UTILS		*/
int					ft_atoi(char *str);

#endif