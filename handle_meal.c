/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/19 15:03:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while(1)
	{
		eat(philo);
		rivotril(philo);
		sophos(philo);
	}
	return (arg);
}

void	start_meal(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	(void) av;
	(void) philos;
	i = 0;
	table->time = get_current_time();
	if (pthread_create(&table->table, NULL, waiter, table) != 0)
		write(2, "TError\n", 7);
	while (i < table->philos->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
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
	pthread_join(table->table, NULL);
}

void	end_meal(t_table *table, t_philos *philos, char **av)
{
	(void) av;
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&table->mutex);
	while (i < table->philos->num_philos)
	{
		pthread_mutex_destroy(&philos[i].fork);
		i++;
	}
}
