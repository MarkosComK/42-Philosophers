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

static bool	is_alive(t_philos *philos, int mode)
{
	sem_wait(philos->table->waiter);
	if (!philos->is_alive)
	{
		sem_post(philos->table->waiter);
		sem_post(philos->table->forks);
		if (mode == 2)
			sem_post(philos->table->forks);
		return (false);
	}
	sem_post(philos->table->waiter);
	return (true);
}

void	eating(t_philos *philos)
{
	sem_wait(philos->table->forks);
	if (!is_alive(philos, 1))
		return ;
	thread_printf(philos, "has taken a fork");
	sem_wait(philos->table->forks);
	if (!is_alive(philos, 2))
		return ;
	thread_printf(philos, "has taken a fork");
	thread_printf(philos, "is eating");
	sem_wait(philos->table->waiter);
	philos->last_meal_time = get_current_time();
	sem_post(philos->table->waiter);
	ft_usleep(philos->eat_time);
	if (!is_alive(philos, 2))
		return ;
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
