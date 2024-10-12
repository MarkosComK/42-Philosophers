/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:50:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/10/01 18:38:50 by mariaoli         ###   ########.fr       */
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
