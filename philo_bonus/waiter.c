
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:31:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/21 16:51:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philosophers_state(t_philos *philo)
{
	if (*philo->dead < philo->num_philos)
		return (1);
	return (0);
}

int	philosopher_dead(t_philos *philo)
{
	if (get_current_time() - philo->last_meal > philo->time_die)
		return (1);
	return (0);
}

int	philo_exist(t_philos *philo)
{
	if (philo->philo)
		return (1);
	return (0);
}

int	philo_dead(t_philos *philo)
{
	if (philosopher_dead(philo))
	{
		thread_dead(philo, "died");
		sem_post(philo->table->dead);
		return (1);
	}
	return (0);
}
/*
int	check_eaten(t_philos *philo)
{
	size_t	i;
	int		total;

	i = 0;
	total = 0;
	while (i < philo[0].num_philos)
	{
		pthread_mutex_lock(philo->table->eatentex);
		if (philo[i].eaten >= philo->table->num_of_meals && philo->table->num_of_meals != -1)
			total++;
		pthread_mutex_unlock(philo->table->eatentex);
		i++;
	}
	if (total == (int)philo[0].num_philos)
	{
		pthread_mutex_lock(philo->table->deadtex);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->table->deadtex);
		return (1);
	}
	return (0);
}
*/
void	*waiter(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
		if (philo_dead(philo) /*|| check_eaten(philos)*/)
			break ;
	return (arg);
}
