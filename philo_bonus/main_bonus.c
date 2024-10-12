/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:15:02 by mariaoli          #+#    #+#             */
/*   Updated: 2024/10/01 18:30:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_table(t_table *table)
{
	if (table)
	{
		if (table->forks_sem)
			sem_close(table->forks_sem);
		if (table->stop_sem)
			sem_close(table->stop_sem);
		if (table->monitor_sem)
			sem_close(table->monitor_sem);
		free(table);
	}
}

static void	kill_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		sem_wait(table->stop_sem);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		kill(table->philos[i].pid, SIGKILL);
		i++;
	}
}

static void	wait_child_processes(t_table *table)
{
	int	i;
	int	status;

	i = 0;
	while (i < table->philo_count)
	{
		waitpid(table->philos[i].pid, &status, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_table	*table;

	if (!check_args(argc, argv))
		return (1);
	table = init(argv);
	if (!table)
		return (1);
	i = 0;
	while (i < table->philo_count)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid == -1)
			return (1);
		if (table->philos[i].pid == 0)
			philo_process(&table->philos[i]);
		i++;
	}
	kill_processes(table);
	wait_child_processes(table);
	free(table->philos);
	free_table(table);
	unlink_sem();
	return (0);
}
