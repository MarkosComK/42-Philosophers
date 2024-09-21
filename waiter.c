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

int	philosophers_state(t_philos *philo)
{
	pthread_mutex_lock(philo->table->deadtex);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->table->deadtex), 1);
	pthread_mutex_unlock(philo->table->deadtex);
	return (0);
}

int	philosopher_dead(t_philos *philo)
{
	pthread_mutex_lock(philo->mealtex);
	if (get_current_time() - philo->last_meal >= philo->time_die)
		return (pthread_mutex_unlock(philo->mealtex), 1);
	pthread_mutex_unlock(philo->mealtex);
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
			pthread_mutex_lock(philo->table->deadtex);
			thread_printf(philo, RED"died"DEFAULT);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->table->deadtex);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*waiter(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
		if (philo_dead(philos))
			break ;
	return (arg);
}
