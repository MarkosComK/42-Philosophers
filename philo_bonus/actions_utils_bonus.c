/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:28 by mariaoli          #+#    #+#             */
/*   Updated: 2024/10/01 18:28:28 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_wait(t_philos *philos, size_t interval)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < interval)
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

void	print_message(t_philos *philos, int c)
{
	size_t	elapsed;

	sem_wait(philos->table->waiter);
	if (philos->is_alive)
	{
		elapsed = elapsed_time(philos->table->start_time);
		if (c == 'f')
			printf(GRAY MESSAGE_FORK DEFAULT, elapsed, philos->id);
		if (c == 'e')
			printf(MAGENTA MESSAGE_EAT DEFAULT, elapsed, philos->id);
		if (c == 's')
			printf(BLUE MESSAGE_SLEEP DEFAULT, elapsed, philos->id);
		if (c == 't')
			printf(YELLOW MESSAGE_THINK DEFAULT, elapsed, philos->id);
	}
	sem_post(philos->table->waiter);
}

void	thread_printf(t_philos *philo, char	*msg)
{
	sem_wait(philo->table->waiter);
	if (philo->is_alive)
	{
		printf(WHITE"%4zi "DEFAULT, get_time() - philo->table->start_time);
		if (ft_strcmp(msg, "has taken a fork") == 0)
			printf(BOLD"%i "GREEN"%s %8s\n"DEFAULT, philo->id, msg, "🍽️");
		else if (ft_strcmp(msg, "is eating") == 0)
			printf(BOLD"%i "BLUE"%12s %9s\n"DEFAULT, philo->id, msg, "🥘");
		else if (ft_strcmp(msg, "is sleeping") == 0)
			printf(BOLD"%i "GRAY"%13s %8s\n"DEFAULT, philo->id, msg, "💤");
		else if (ft_strcmp(msg, "is thinking") == 0)
			printf(BOLD"%i "MAGENTA"%13s %8s\n"DEFAULT, philo->id, msg, "🤔");
		else if (ft_strcmp(msg, "died") == 0)
			printf(RED"%i %9s %14s\n"DEFAULT, philo->id, msg, "☠️");
	}
	sem_post(philo->table->waiter);
}
