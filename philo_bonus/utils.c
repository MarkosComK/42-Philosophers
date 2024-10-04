/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:24:12 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 18:33:42 by marsoare         ###   ########.fr       */
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

void	print_philo(t_philos *philo)
{
	printf(YELLOW"philo->id:"GREEN"        [% 8i]\n", philo->id);
	printf(YELLOW"philo->num_philos:"GREEN"[% 8i]\n", philo->num_philos);
	printf(YELLOW"philo->time-die:"GREEN"  [% 8zi]\n", philo->time_die);
	printf(YELLOW"philo->time-eat:"GREEN"  [% 8zi]\n", philo->time_eat);
	printf(YELLOW"philo->time-sleep:"GREEN"[% 8zi]\n", philo->time_sleep);
	printf(YELLOW"philo->sleep:"GREEN"     [% 8i]\n", philo->sleep);
	printf(YELLOW"philo->eat:"GREEN"       [% 8i]\n", philo->eaten);
	printf(YELLOW"philo->dead:"GREEN"      [% 8i]\n", *philo->dead);
	printf("\n"DEFAULT);
}

void	thread_printf(t_philos *philo, char	*msg)
{
	//printf("time dif: %zi\n", get_current_time() - philo->table->time);
	printf("dead-state: %i\n", *philo->dead);
	printf("last-meal: %zi\n", get_current_time() - philo->last_meal);
	if (*philo->dead == philo->num_philos)
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
}
