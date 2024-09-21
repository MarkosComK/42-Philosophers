/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:15:48 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 15:38:50 by marsoare         ###   ########.fr       */
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
	if (!*philo->dead)
	{
		pthread_mutex_lock(&philo->table->mutex);
		printf(WHITE"%4zi "DEFAULT, get_current_time() - philo->table->time);
		if (ft_strcmp(msg, "has taken a fork") == 0)
			printf(BOLD"%i "GREEN"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is eating") == 0)
			printf(BOLD"%i "YELLOW"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is sleeping") == 0)
			printf(BOLD"%i "GRAY"%s\n"DEFAULT, philo->id, msg);
		else if (ft_strcmp(msg, "is thinking") == 0)
			printf(BOLD"%i "RED"%s\n"DEFAULT, philo->id, msg);
		else
			printf(RED"%i "GRAY"%s\n", philo->id, msg);
		pthread_mutex_unlock(&philo->table->mutex);
	}
}
