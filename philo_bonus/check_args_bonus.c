/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:51:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/12 15:51:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf(RED"Usage:\n"GREEN"./philo"" 5 500 600 800\n" DEFAULT));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf(RED"Invalid number of philosophers\n"DEFAULT));
	if (ft_atoi(av[2]) <= 0 || ft_isnum(av[2]))
		return (printf(RED"Invalid time_to_die\n"DEFAULT));
	if (ft_atoi(av[3]) <= 0 || ft_isnum(av[3]))
		return (printf(RED"Invalid time_to_eat\n"DEFAULT));
	if (ft_atoi(av[4]) <= 0 || ft_isnum(av[4]))
		return (printf(RED"Invalid time_to_sleep\n"DEFAULT));
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_isnum(av[5])))
		return (printf(RED"Invalid eat_times\n"DEFAULT));
	return (0);
}

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
