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
	t_philos	*next;
	t_philos	*own;

	own = philo;

	if (philo->id == (int)philo->num_philos)
	{
		next = &philo->table->philos[0];
	}
	else
		next = &philo->table->philos[philo->id];
	//printf("my fork %p \nnext %p\n\n", &philo->fork, &next->fork);
//lock own fork
	pthread_mutex_lock(&own->fork);
	thread_printf(philo, "has taken a fork");
//lock next fork
	pthread_mutex_lock(&next->fork);
	pthread_mutex_lock(&philo->table->mutex);
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" has taken a fork\n"DEFAULT, philo->id);
//start eating
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is eating\n"DEFAULT, philo->id);
	pthread_mutex_unlock(&philo->table->mutex);
	ft_usleep(philo->time_eat);
//after eat goes sleep
	pthread_mutex_unlock(&own->fork);
	pthread_mutex_unlock(&next->fork);
}

void	rivotril(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->mutex);
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is sleeping\n"DEFAULT, philo->id);
	pthread_mutex_unlock(&philo->table->mutex);
	ft_usleep(philo->time_sleep);
}

void	sophos(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->mutex);
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is thinking\n"DEFAULT, philo->id);
	pthread_mutex_unlock(&philo->table->mutex);
}

int	thread_printf(t_philos *philo, char	*msg)
{
	int	written;

	written = 0;
	pthread_mutex_lock(&philo->table->mutex);
	written += printf("%zi ", get_current_time() - philo->table->time);
	written += printf(BLUE"%i"GREEN" %s\n"DEFAULT, philo->id, msg);
	pthread_mutex_unlock(&philo->table->mutex);
	return (written);
}
