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
	sem_wait(philos->table->monitor_sem);
	if (!philos->is_alive)
	{
		sem_post(philos->table->monitor_sem);
		sem_post(philos->table->forks_sem);
		if (mode == 2)
			sem_post(philos->table->forks_sem);
		return (false);
	}
	sem_post(philos->table->monitor_sem);
	return (true);
}

void	eating(t_philos *philos)
{
	sem_wait(philos->table->forks_sem);
	if (!is_alive(philos, 1))
		return ;
	print_message(philos, 'f');
	sem_wait(philos->table->forks_sem);
	if (!is_alive(philos, 2))
		return ;
	print_message(philos, 'f');
	print_message(philos, 'e');
	sem_wait(philos->table->monitor_sem);
	philos->last_meal_time = get_time();
	sem_post(philos->table->monitor_sem);
	ft_wait(philos, philos->eat_time);
	if (!is_alive(philos, 2))
		return ;
	sem_wait(philos->table->monitor_sem);
	philos->meals_eaten += 1;
	sem_post(philos->table->monitor_sem);
	sem_post(philos->table->forks_sem);
	sem_post(philos->table->forks_sem);
}

void	sleeping(t_philos *philos)
{
	print_message(philos, 's');
	ft_wait(philos, philos->sleep_time);
}

void	thinking(t_philos *philos)
{
	print_message(philos, 't');
}
