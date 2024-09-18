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
		next = &philo->table->philos[philo->id];
		own = &philo->table->philos[0];
	}
	else
		next = &philo->table->philos[philo->id];
	//printf("my fork %p \nnext %p\n\n", &philo->fork, &next->fork);
//lock own fork
	pthread_mutex_lock(&own->fork);
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" has taken a fork\n"DEFAULT, philo->id);
//lock next fork
	if(pthread_mutex_lock(&next->fork))
		printf("error taking next fork");
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" has taken a fork\n"DEFAULT, philo->id);
//start eating
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is eating\n"DEFAULT, philo->id);
	ft_usleep(philo->time_eat);
//after eat goes sleep
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is sleeping\n"DEFAULT, philo->id);
	if (pthread_mutex_unlock(&own->fork))
		printf("error unlocking own fork\n");
	if (pthread_mutex_unlock(&next->fork))
		printf("error unlocking next fork\n");
	ft_usleep(philo->time_sleep);
}

void	rivotril(t_philos *philo)
{
	if (philo->sleep == 1)
	{
	}
}

void	sophos(t_philos *philo)
{
	printf("%zi ", get_current_time() - philo->table->time);
	printf(BLUE"%i"GREEN" is thinking\n"DEFAULT, philo->id);
}
