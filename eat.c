/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:32:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/15 16:16:04 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philos *philo)
{
	int	next;
	int	last;

	next = philo->id;
	last = philo->num_philos - 1;
	pthread_mutex_lock(&philo->table->mutex);
	while (philo->forks != 2 && philo->table->forks != 0)
	{
		philo->forks++;
		philo->table->forks--;
		printf("%zi ", get_current_time() - philo->table->time);
		printf(BLUE"%i"GREEN" has taken a fork\n"DEFAULT, philo->id);
	}
	if (philo->forks == 2)
	{
		printf("%zi ", get_current_time() - philo->table->time);
		printf(BLUE"%i"GREEN" is eating\n"DEFAULT, philo->id);
	}
	pthread_mutex_unlock(&philo->table->mutex);
}
