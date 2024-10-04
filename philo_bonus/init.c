/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 18:31:22 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_table(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	table->num_philos = ft_atoi(av[1]);
	table->philos = philos;
	sem_unlink("forks");
	table->forks = sem_open("forks", O_CREAT, 0644, table->num_philos);
	sem_unlink("dead");
	table->dead = sem_open("dead", O_CREAT, 0644, table->num_philos);
	sem_unlink("meal");
	table->meal = sem_open("meal", O_CREAT, 0644, 0);
	i = 0;
	table->dead_flag = table->num_philos;
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	else
		table->num_of_meals = -1;
}

void	init_philos(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos_input_data(&philos[i], av);
		i++;
	}
}

void	philos_input_data(t_philos *philos, char **av)
{
	philos->num_philos = ft_atoi(av[1]);
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->last_meal = get_current_time();
	philos->sleep = 0;
	philos->eaten = 0;
	philos->dead = &philos->table->dead_flag;
}
