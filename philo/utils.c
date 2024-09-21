/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:15:48 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/21 15:48:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	print_philos(t_philos *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].num_philos)
	{
		printf("philo: %zi\n", i + 1);
		printf(YELLOW"philo->num_philos:"GREEN"[% 8zi]\n", philo[i].num_philos);
		printf(YELLOW"philo->fork:"GREEN"[%8p]\n", &philo[i].fork);
		printf(YELLOW"philo->time-die:"GREEN"  [% 8zi]\n", philo[i].time_die);
		printf(YELLOW"philo->time-eat:"GREEN"  [% 8zi]\n", philo[i].time_eat);
		printf(YELLOW"philo->time-sleep:"GREEN"[% 8zi]\n", philo[i].time_sleep);
		printf(YELLOW"philo->sleep:"GREEN"[% 8i]\n", philo[i].sleep);
		printf(YELLOW"philo->eat:"GREEN"[% 8i]\n", philo[i].eaten);
		printf(YELLOW"philo->dead:"GREEN"[% 8i]\n", *philo[i].dead);
		printf("\n"DEFAULT);
		i++;
	}
	printf("\n");
}

void	thread_printf(t_philos *philo, char	*msg)
{
	pthread_mutex_lock(&philo->table->mutex);
	if (!*philo->dead)
	{
		printf(WHITE"%4zi "DEFAULT, get_current_time() - philo->table->time);
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
	pthread_mutex_unlock(&philo->table->mutex);
}
