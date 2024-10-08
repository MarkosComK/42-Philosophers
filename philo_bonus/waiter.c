
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

//IDK why i have those next 2 functions but i'll not toutch them
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
		sem_post(philo->table->dead);
		*philo->dead = 1;
		thread_dead(philo, "died");
		sem_wait(philo->table->print);
		philo->table->p_flag--;
		sem_post(philo->table->print);
		return (1);
	}
	return (0);
}

void	*waiter(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		if (philo_dead(philo))
			break ;
	}
	return (arg);
}
