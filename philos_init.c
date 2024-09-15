/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:55:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/15 16:39:21 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_input_data(t_philos *philos, char **av)
{
	philos->num_philos = ft_atoi(av[1]);
	philos->forks = 0;
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->sleep = 0;
}

void	init_philos(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos_input_data(&philos[i], av);
		philos[i].table = table;
		i++;
	}
}
