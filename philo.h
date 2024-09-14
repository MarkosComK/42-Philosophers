/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:31:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 14:47:11 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <pthread.h>
# include <stdio.h>

# define MAX_PHILOS 200

typedef struct s_philos
{
	pthread_t	thread;
	size_t	num_philos;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
}				t_philos;

typedef struct s_table
{
	pthread_t	table;
	t_philos	*philos;
}				t_table;

void	prepare_table(t_philos *philos, t_table *table, char **av);
void	init_philos(t_table *table, t_philos *philos, char **av);
void	birth_sophos(t_table *table, t_philos *philos, char **av);
int	check_args(int ac, char **av);
//utils.c
int	ft_atoi(char *str);
int	ft_isnum(char *str);
void	print_philo(t_philos *philo);

#endif
