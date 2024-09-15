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
	int	next;
	int	last;

	next = philo->id;
	last = philo->num_philos - 1;
	while (!philo->sleep)
	{
		pthread_mutex_lock(&philo->table->mutex);
		if (philo->table->forks > 0)
		{
			philo->forks++;
			philo->table->forks--;
			printf("%zi ", get_current_time() - philo->table->time);
			printf(BLUE"%i"GREEN" has taken a fork\n"DEFAULT, philo->id);
		}
		pthread_mutex_unlock(&philo->table->mutex);
		if (philo->forks == 2)
			break ;
	}
	if (philo->forks == 2)
	{
		philo->sleep = 1;
		printf("%zi ", get_current_time() - philo->table->time);
		pthread_mutex_lock(&philo->table->mutex);
		printf(BLUE"%i"GREEN" is eating\n"DEFAULT, philo->id);
		pthread_mutex_unlock(&philo->table->mutex);
		ft_usleep(philo->time_eat);
	}
}

void	rivotril(t_philos *philo)
{
	if (philo->sleep == 1)
	{
		while(get_current_time() - philo->table->time < philo->time_eat);
		pthread_mutex_lock(&philo->table->mutex);
		philo->forks -= 2;
		philo->table->forks += 2;
		printf("%zi ", get_current_time() - philo->table->time);
		printf(BLUE"%i"GREEN" is sleeping\n"DEFAULT, philo->id);
		pthread_mutex_unlock(&philo->table->mutex);
	}
}
