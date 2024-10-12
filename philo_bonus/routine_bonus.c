/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:52:52 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/12 15:52:54 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philos *philos)
{
	sem_wait(philos->table->forks);
	thread_printf(philos, "has taken a fork");
	sem_wait(philos->table->forks);
	thread_printf(philos, "has taken a fork");
	thread_printf(philos, "is eating");
	sem_wait(philos->table->waiter);
	philos->last_meal_time = get_current_time();
	sem_post(philos->table->waiter);
	ft_usleep(philos->eat_time);
	sem_wait(philos->table->waiter);
	philos->eaten += 1;
	sem_post(philos->table->waiter);
	sem_post(philos->table->forks);
	sem_post(philos->table->forks);
}

void	sleeping(t_philos *philos)
{
	thread_printf(philos, "is sleeping");
	ft_usleep(philos->sleep_time);
}

void	thinking(t_philos *philos)
{
	thread_printf(philos, "is thinking");
}
