/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:31:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:19 by marsoare         ###   ########.fr       */
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

# define MAX_PHILOS 200

typedef struct s_philos
{
	pthread_t		philo;
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
	size_t			num_philos;
	pthread_t		table;
	t_philos		*philos;
	int				num_of_meals;
	unsigned long	time;
	int				dead_flag;
}				t_table;

//checkers.c
int		check_args(int ac, char **av);
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isnum(char *str);
//init.c
void	init_philos(t_table *table, t_philos *philos, char **av);
void	init_table(t_table *table, t_philos *philos, char **av);
//utils.c
void	print_philo(t_philos *philo);

#endif
