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

//IDK if dead_flag is being used, but its working
t_table	*init_table(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->num_philos = ft_atoi(av[1]);
	table->philos = (t_philos *)malloc(sizeof(t_philos) * table->num_philos);
	sem_unlink("forks");
	table->forks = sem_open("forks", O_CREAT, 0644, table->num_philos);
	sem_unlink("finish");
	table->finish= sem_open("finish", O_CREAT, 0644, 0);
	sem_unlink("waiter");
	table->waiter= sem_open("waiter", O_CREAT, 0644, 1);
	table->dead_flag = table->num_philos;
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	else
		table->num_of_meals = -1;
	return (table);
}

void	init_philos(t_table *table, t_philos *philos, char **av, int i)
{
	philos->alive = 1;
	philos->num_philos = ft_atoi(av[1]);
	//philos->is_full = false;
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->last_meal= get_current_time();
	philos->eaten = 0;
	philos->table = table;
	philos->id = i + 1;
	philos->table = table;
}

void	philos_input_data(t_philos *philos, char **av)
{
	philos->num_philos = ft_atoi(av[1]);
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->last_meal = get_current_time();
	philos->sleep = 0;
	philos->alive = 1;
	philos->eaten = 0;
}
