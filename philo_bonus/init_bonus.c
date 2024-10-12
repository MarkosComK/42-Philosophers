/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:52:05 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/12 15:52:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_table	*init_table(char **argv)
{
	t_table	*table;
	int		i;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_count = ft_atoi(argv[1]);
	table->start_time = get_current_time();
	if (!init_sem(table))
		return (free(table), NULL);
	table->philos = (t_philos *)malloc(sizeof(t_philos) * table->philo_count);
	if (!table->philos)
		return (free(table), NULL);
	i = 0;
	while (i < table->philo_count)
	{
		init_philos(&table->philos[i], table, i, argv);
		i++;
	}
	return (table);
}

void	init_philos(t_philos *philos, t_table *table, int i, char **argv)
{
	philos->id = i + 1;
	philos->is_alive = true;
	philos->is_full = false;
	philos->die_time = ft_atoi(argv[2]);
	philos->eat_time = ft_atoi(argv[3]);
	philos->last_meal_time = table->start_time;
	philos->sleep_time = ft_atoi(argv[4]);
	philos->to_eat = -1;
	if (argv[5])
		philos->to_eat = ft_atoi(argv[5]);
	philos->eaten = 0;
	philos->table = table;
}

int	init_sem(t_table *table)
{
	unlink_sem();
	table->forks= sem_open("forks", O_CREAT, 0644, table->philo_count);
	if (table->forks== SEM_FAILED)
		return (0);
	table->finish = sem_open("finish", O_CREAT, 0644, 0);
	if (table->finish == SEM_FAILED)
		return (0);
	table->waiter = sem_open("waiter", O_CREAT, 0644, 1);
	if (table->waiter == SEM_FAILED)
		return (0);
	return (1);
}

void	unlink_sem(void)
{
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("waiter");
}
