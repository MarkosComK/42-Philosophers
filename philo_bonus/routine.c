/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:42:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 17:57:13 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	/*
	if (ft_one_philo(philo))
		return (arg);
	*/
	while (1/*!philosophers_state(philo)*/)
	{
		eat(philo);
		rivotril(philo);
		sophos(philo);
	}
	return (arg);
}

void	eat(t_philos *philo)
{
	sem_wait(philo->table->forks);
	thread_printf(philo, "has taken a fork");
	sem_wait(philo->table->forks);
	thread_printf(philo, "has taken a fork");
	thread_printf(philo, "is eating");
	philo->last_meal = get_current_time();
	ft_usleep(philo->time_eat);
	philo->eaten++;
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
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
