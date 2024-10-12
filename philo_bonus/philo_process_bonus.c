/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:54:13 by marianamora       #+#    #+#             */
/*   Updated: 2024/10/01 18:25:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_process(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->table->philo_count)
	{
		sem_post(philos->table->stop_sem);
		i++;
	}
	free_table(philos->table);
	exit (0);
}

void	*monitoring(void *arg)
{
	size_t		elapsed_meal_time;
	size_t		elapsed;
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
	{
		sem_wait(philos->table->monitor_sem);
		elapsed_meal_time = elapsed_time(philos->last_meal_time);
		if (elapsed_meal_time > philos->die_time && philos->is_alive)
		{
			philos->is_alive = false;
			sem_post(philos->table->monitor_sem);
			elapsed = elapsed_time(philos->table->start_time);
			printf(RED MESSAGE_DEATH DEFAULT, elapsed, philos->id);
			cleanup_process(philos);
			break ;
		}
		sem_post(philos->table->monitor_sem);
		usleep(500);
	}
	return (NULL);
}

void	philo_process(t_philos *philos)
{
	if (pthread_create(&philos->monitor_thread, NULL, &monitoring, philos) != 0)
		printf("Error: pthread_create\n");
	if (philos->id % 2 == 0)
		usleep(500);
	while (1)
	{
		eating(philos);
		if (philos->meals_eaten == philos->meals_to_eat)
			sem_post(philos->table->stop_sem);
		sleeping(philos);
		thinking(philos);
		usleep(100);
	}
}
