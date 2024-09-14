/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 17:08:38 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	pthread_mutex_lock(&((t_table *)arg)->mutex);
	printf("Hi im philo N: %i\n", ((t_philos *)arg)->id);
	pthread_mutex_unlock(&((t_table *)arg)->mutex);
	//somehow implement mutexes for forks
	//eat
	//sleep
	//think
	return (arg);
}

void	*observe(void *arg)
{
	printf(BLUE"Hi im the waiter!\n"DEFAULT);
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
	pthread_create(&table->table, NULL, observe, NULL);
	while (i++ < table->philos->num_philos)
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
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
