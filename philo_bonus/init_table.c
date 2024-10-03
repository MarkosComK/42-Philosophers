/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/03 19:32:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	prepare_table(t_philos *philos, t_table *table, char **av)
{
	size_t	i;

	table->philos = philos;
	pthread_mutex_init(&table->mutex, NULL);
	table->deadtex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->deadtex, NULL);
	table->eatentex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->eatentex, NULL);
	i = 0;
	table->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < (size_t)ft_atoi(av[1]))
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	table->dead_flag = 0;
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	else
		table->num_of_meals = -1;
}
