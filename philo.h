/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:31:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/19 14:38:27 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

# define MAX_PHILOS 200

typedef struct s_philos
{
	int				id;
	pthread_t		thread;
	size_t			num_philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*mealtex;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			last_meal;
	int				sleep;
	int				eat;
	int				*dead;
	struct s_table	*table;
}				t_philos;

typedef struct s_table
{
	pthread_t		table;
	t_philos		*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*deadtex;
	unsigned long	time;
	int				dead_flag;
}				t_table;

//checkers.c
int		check_args(int ac, char **av);
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isnum(char *str);
//eat.c
void	eat(t_philos *philos);
void	rivotril(t_philos *philo);
void	sophos(t_philos *philo);
void	thread_printf(t_philos *philo, char	*msg);
//get_time.c
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
//handle_meal.c
void	*routine(void *arg);
void	start_meal(t_table *table, t_philos *philos, char **av);
void	end_meal(t_table *table, t_philos *philos, char **av);
//main.c
//init.c
void	philos_input_data(t_philos *philos, char **av);
void	init_philos(t_table *table, t_philos *philos, char **av);
void	prepare_table(t_philos *philos, t_table *table, char **av);
//utils.c
int		ft_strcmp(char *s1, char *s2);
void	print_philos(t_philos *philo);
//waiter
int		philosophers_state(t_philos *philo);
int		philosopher_dead(t_philos *philo);
int		philo_dead(t_philos *philo);
void	*waiter(void *arg);

#endif
