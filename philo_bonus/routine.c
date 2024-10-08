/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:42:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 18:33:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_one_philo(t_philos *philo)
{
	ft_usleep(1);
	if (philo->num_philos == 1)
	{
		sem_wait(philo->table->forks);
		thread_printf(philo, "has taken a fork");
		sem_post(philo->table->forks);
		ft_usleep(philo->time_die);
		thread_printf(philo, "died");
		sem_close(philo->table->dead);
		sem_close(philo->table->forks);
		sem_close(philo->table->meals);
		sem_close(philo->table->print);
		pthread_join(philo->waiter, NULL);
		return (0);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	pthread_create(&philo->waiter, NULL, waiter, philo);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	if (ft_one_philo(philo))
		return (arg);
	while (!philosopher_dead(philo))
	{
		eat(philo);
		if (philo->eaten == philo->table->num_of_meals)
		{
			sem_post(philo->table->meals);
			break ;
		}
		rivotril(philo);
		sophos(philo);
	}
	sem_close(philo->table->dead);
	sem_close(philo->table->forks);
	sem_close(philo->table->meals);
	sem_close(philo->table->print);
	pthread_join(philo->waiter, NULL);
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
