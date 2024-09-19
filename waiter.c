/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:31:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/19 14:31:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	philo_dead(t_philos *philo)
{
	size_t	time;

	time = get_current_time();
	if (time - philo->last_meal >= philo->time_die)
	{
		printf(RED"%i is dead\n"DEFAULT, philo->id);
		return (1);
	}
	return (0);
}

void	*observe(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
		if (philo_dead(table->philos)) //implement a loop to check each philosopher is dead or not
	printf(BLUE"Hi im the waiter!\n"DEFAULT);
	return (arg);
}

