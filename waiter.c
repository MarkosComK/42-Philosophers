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

int	philosopher_state(t_philos *philo)
{
	pthread_mutex_lock(&philo->deadtex);
	if (philo->dead)
		return (pthread_mutex_unlock(&philo->deadtex), 1);
	pthread_mutex_unlock(&philo->deadtex);
	return (0);
}

int	philosopher_dead(t_philos *philo)
{
	pthread_mutex_lock(&philo->mealtex);
	if (get_current_time() - philo->last_meal >= philo->time_die
	/*&& philo->eat == 0*/)
		return (pthread_mutex_unlock(&philo->mealtex), 1);
	pthread_mutex_unlock(&philo->mealtex);
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
			pthread_mutex_lock(&philo[0].deadtex);
			thread_printf(philo, RED"died"DEFAULT);
			philo[i].dead = 1;
			pthread_mutex_unlock(&philo[0].deadtex);
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
	return (arg);
}

