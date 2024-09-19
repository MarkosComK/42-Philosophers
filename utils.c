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

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (-1);
	while (str[size])
		size++;
	return (size);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	neg;

	result = 0;
	i = 0;
	neg = 1;
	if (!str)
		return (-1);
	while (str[i] >= '\t' && str[i] <= '\r' && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * neg);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i++] > '9')
			return (1);
	}
	return (0);
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
		printf(YELLOW"philo->eat:"GREEN"[% 8i]\n", philo[i].eat);
		printf("\n"DEFAULT);
		i++;
	}
	printf("\n");
}
