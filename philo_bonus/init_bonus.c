/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:50:25 by marianamora       #+#    #+#             */
/*   Updated: 2024/10/01 18:24:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philos(t_philos *philos, t_table *table, int i, char **argv)
{
	philos->id = i + 1;
	philos->is_alive = true;
	philos->is_full = false;
	philos->die_time = ft_atoi(argv[2]);
	philos->eat_time = ft_atoi(argv[3]);
	philos->last_meal_time = table->start_time;
	philos->sleep_time = ft_atoi(argv[4]);
	philos->meals_to_eat = -1;
	if (argv[5])
		philos->meals_to_eat = ft_atoi(argv[5]);
	philos->meals_eaten = 0;
	philos->table = table;
}

static int	init_sem(t_table *table)
{
	unlink_sem();
	table->forks_sem = sem_open("forks_sem", O_CREAT, 0644, table->philo_count);
	if (table->forks_sem == SEM_FAILED)
		return (0);
	table->stop_sem = sem_open("stop_sem", O_CREAT, 0644, 0);
	if (table->stop_sem == SEM_FAILED)
		return (0);
	table->monitor_sem = sem_open("monitor_sem", O_CREAT, 0644, 1);
	if (table->monitor_sem == SEM_FAILED)
		return (0);
	return (1);
}

void	unlink_sem(void)
{
	sem_unlink("forks_sem");
	sem_unlink("stop_sem");
	sem_unlink("monitor_sem");
}

t_table	*init(char **argv)
{
	t_table	*table;
	int		i;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_count = ft_atoi(argv[1]);
	table->start_time = get_time();
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
