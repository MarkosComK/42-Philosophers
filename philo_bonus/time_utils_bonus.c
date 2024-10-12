/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:23:03 by mariaoli          #+#    #+#             */
/*   Updated: 2024/09/24 15:28:59 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	elapsed_time(size_t start_time)
{
	size_t	elapsed;

	elapsed = get_current_time() - start_time;
	return (elapsed);
}

void	ft_wait(t_philos *philos, size_t interval)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < interval)
	{
		sem_wait(philos->table->waiter);
		if (!philos->is_alive)
		{
			sem_post(philos->table->waiter);
			break ;
		}
		sem_post(philos->table->waiter);
		usleep(100);
	}
}
