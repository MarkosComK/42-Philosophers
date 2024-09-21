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
	t_philos	next;
	t_philos	own;

	own = *philo;

	if (philo->id == (int)philo->num_philos)
	{
		next = philo->table->philos[0];
	}
	else
		next = philo->table->philos[philo->id];
	//printf("my fork %p \nnext %p\n\n", &philo->fork, &next->fork);
//lock own fork
	pthread_mutex_lock(own.fork);
	thread_printf(philo, "has taken a fork");
//lock next fork
	pthread_mutex_lock(next.fork);
	thread_printf(philo, "has taken a fork");
//start eating
	thread_printf(philo, "is eating");
	pthread_mutex_lock(own.mealtex);
	philo->last_meal = get_current_time();
	philo->eat++;
	pthread_mutex_unlock(own.mealtex);
	ft_usleep(philo->time_eat);
//after eat goes sleep
	pthread_mutex_unlock(own.fork);
	pthread_mutex_unlock(next.fork);
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

int	thread_printf(t_philos *philo, char	*msg)
{
	int	written;

	written = 0;
	if (!*philo->dead)
	{
		pthread_mutex_lock(&philo->table->mutex);
		written += printf(WHITE"%4zi "DEFAULT, get_current_time() - philo->table->time);
		if (ft_strcmp(msg, "has taken a fork") == 0)
			written += printf(BRIGHT_GREEN"%i "GREEN"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is eating") == 0)
			written += printf(YELLOW"%i "YELLOW"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is sleeping") == 0)
			written += printf(LIGHT_GRAY"%i "GRAY"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is thinking") == 0)
			written += printf(RED"%i "RED"%s\n"DEFAULT, philo->id, msg);
		else
			written += printf(RED"%i "GRAY"%s\n", philo->id, msg);
		pthread_mutex_unlock(&philo->table->mutex);
	}
	return (written);
}
