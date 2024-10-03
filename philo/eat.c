/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:32:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/15 19:15:30 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philos *philo)
{
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	*own_fork;

	own_fork = &philo->table->forks[(philo->id - 1) % philo->num_philos];
	next_fork = &philo->table->forks[(philo->id) % philo->num_philos];
	if (philo->id % 2 == 0) {
		next_fork = own_fork;
		own_fork = &philo->table->forks[(philo->id) % philo->num_philos];
	}
	pthread_mutex_lock(own_fork);
	thread_printf(philo, "has taken a fork");
	pthread_mutex_lock(next_fork);
	thread_printf(philo, "has taken a fork");
	thread_printf(philo, "is eating");
	pthread_mutex_lock(philo->mealtex);
	philo->last_meal = get_current_time();
	pthread_mutex_lock(philo->table->eatentex);
	philo->eaten++;
	pthread_mutex_unlock(philo->table->eatentex);
	pthread_mutex_unlock(philo->mealtex);
	ft_usleep(philo->time_eat);
	pthread_mutex_unlock(own_fork);
	pthread_mutex_unlock(next_fork);
}

void	rivotril(t_philos *philo)
{
	thread_printf(philo, "is sleeping");
	ft_usleep(philo->time_sleep);
}

void	sophos(t_philos *philo)
{
	thread_printf(philo, "is thinking");
}
