/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 20:30:53 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	//pthread_mutex_lock(&((t_table *)arg)->mutex);
	printf("Hi im philo N: %i\n", philo->id);
	//pthread_mutex_unlock(&((t_table *)arg)->mutex);
	//somehow implement mutexes for forks
	//eat
	//sleep
	//think
	return (arg);
}

void	*observe(void *arg)
{
	//pthread_mutex_lock(&((t_table *)arg)->mutex);
	printf(BLUE"Hi im the waiter!\n"DEFAULT);
	//pthread_mutex_unlock(&((t_table *)arg)->mutex);
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
	if (pthread_create(&table->table, NULL, observe, NULL) != 0)
			write(2, "TError\n", 7);
	while (i < table->philos->num_philos)
	{
		if(pthread_create(&table->philos[i].thread, NULL,
			routine, &table->philos[i]) != 0)
			write(2, "TError\n", 7);
		i++;
	}
	i = 0;
	while (i < table->philos->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

void	end_meal(t_table *table, t_philos *philos, char **av)
{
	(void) av, (void) philos;

	pthread_join(table->table, NULL);
	pthread_mutex_destroy(&table->mutex);
}
