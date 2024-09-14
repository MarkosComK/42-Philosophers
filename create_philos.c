/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 15:27:19 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	printf("routine\n");
	//somehow implement mutexes for forks
	//eat
	//sleep
	//think
	return (arg);
}

void	start_meal(t_table *table, t_philos *philos, char **av)
{
	size_t	i;
	(void) av, (void) philos;

	i = 0;
	pthread_create(&table->table, NULL, routine, NULL);
	while (i < table->philos->num_philos)
		pthread_create(&table->philos[i++].thread, NULL, routine, NULL);
}

void	end_meal(t_table *table, t_philos *philos, char **av)
{
	size_t	i;
	(void) av, (void) philos;

	i = 0;
	while (i < table->philos->num_philos)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(table->table, NULL);
}
