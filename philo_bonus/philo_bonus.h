/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:04:12 by mariaoli          #+#    #+#             */
/*   Updated: 2024/10/01 18:28:14 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
# include "colors.h"

# define ERR_ARG_NUM "Error: Incorrect number of arguments\n"
# define ERR_ARG_INT "Error: Arguments should only contain digits\n"
# define ERR_ARG_LIM "Error: Argument values must be between 1 and INT_MAX\n"

# define MESSAGE_FORK "%zu %d has taken a fork\n"
# define MESSAGE_EAT "%zu %d is eating\n"
# define MESSAGE_SLEEP "%zu %d is sleeping\n"
# define MESSAGE_THINK "%zu %d is thinking\n"
# define MESSAGE_DEATH "%zu %d died\n"

# define ALL_CHILD -1

typedef struct s_table	t_table;
typedef struct s_philos	t_philos;

typedef struct s_philos
{
	pthread_t	monitor_thread;//
	pid_t		pid;
	int			id;
	bool		is_alive;
	bool		is_full;
	size_t		die_time;
	size_t		eat_time;
	size_t		last_meal_time;
	size_t		sleep_time;
	int			meals_to_eat;
	int			meals_eaten;
	t_table		*table;
}	t_philos;

typedef struct s_table
{
	int			philo_count;
	size_t		start_time;
	sem_t		*forks;
	sem_t		*finish;
	sem_t		*waiter;
	t_philos	*philos;
}	t_table;

//checkers.c
int		check_args(int argc, char **argv);
int		ft_atoi(char *ptr);

//init.c
t_table	*init_table(char **argv);
void	init_philos(t_philos *philos, t_table *table, int i, char **argv);
int	init_sem(t_table *table);
void	unlink_sem(void);
//dinner.c
void	start_dinner(t_table *table);
size_t	elapsed_time(size_t start_time);
void	kill_processes(t_table *table);
void	wait_child_processes(t_table *table);
//time_utils.c
size_t	get_current_time(void);
void	ft_wait(t_philos *philos, size_t interval);
//routine.c
void	philo_process(t_philos *philos);
void	eating(t_philos *philos);
void	sleeping(t_philos *philos);
void	thinking(t_philos *philos);
void	free_table(t_table *table);
void	unlink_sem(void);
//utils.c
void	print_message(t_philos *philos, int c);
void	thread_death(t_philos *philo, char	*msg);
void	thread_printf(t_philos *philo, char	*msg);

#endif
