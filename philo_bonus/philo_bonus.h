/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:31:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 18:36:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "colors_bonus.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

# define MAX_PHILOS 200

typedef struct s_philos
{
	pthread_t		philo;
	pthread_t		waiter;
	pid_t			pid;
	int				id;
	int				num_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			last_meal;
	int				sleep;
	int				eaten;
	int				*dead;
	struct s_table	*table;
}				t_philos;

typedef struct s_table
{
	pthread_t		table;
	size_t			num_philos;
	t_philos		*philos;
	sem_t			*forks;
	sem_t			*dead;
	sem_t			*meals;
	sem_t			*print;
	int				p_flag;
	unsigned long	time;
	int				num_of_meals;
	int				dead_flag;
}				t_table;

//check_args.c
int		check_args(int ac, char **av);
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isnum(char *str);
//dinner.c
void	start_dinner(t_table *table, t_philos *philos, char **av);
void	finish_dinner(t_table *table);
//get_time.c
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
//init.c
void	init_table(t_table *table, t_philos *philos, char **av);
void	init_philos(t_table *table, t_philos *philos, char **av);
void	philos_input_data(t_philos *philos, char **av);
//routine.c
void	*routine(void *arg);
void	eat(t_philos *philo);
void	rivotril(t_philos *philo);
void	sophos(t_philos *philo);
//utils.c
void	print_philo(t_philos *philo);
void	thread_dead(t_philos *philo, char	*msg);
void	thread_printf(t_philos *philo, char *msg);
//waiter.c
int		philosophers_state(t_philos *philo);
int		philosopher_dead(t_philos *philo);
int		philo_dead(t_philos *philo);
void	*waiter(void *arg);

#endif
