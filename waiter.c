/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:31:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/19 15:17:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_dead(t_philos *philo)
{
	//pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= philo->time_die)
		return (/*pthread_mutex_unlock(philo->meal_lock), */1);
	//pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	philo_dead(t_philos *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].num_philos)
	{
		if (philosopher_dead(&philo[i]))
		{
			thread_printf(philo, RED"died"DEFAULT);
			//pthread_mutex_lock(philos[0].dead_lock);
			philo->dead = 1;
			//pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*waiter(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
		if (philo_dead(table->philos))
			break ;
	printf(BLUE"Hi im the waiter!\n"DEFAULT);
	return (arg);
}

